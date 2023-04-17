#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  vector<ll> arr;
  ll start, end, root;

  SegTree(ll n) {
    tree = vector<ll>(n * 4);
    arr = vector<ll>(n + 2);
    fill(arr.begin(), arr.end(), 0);
    root = 1;
    start = 1;
    end = n + 1;
  }

  void update(ll target, ll value) {
    arr[target] += value;
    update(root, start, end, target);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll update(ll node, ll start, ll end, ll target) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      return tree[node] = arr[target];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target) + update(node * 2 + 1, mid + 1, end, target);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N, arr[1001000];
  cin >> N;
  for(ll i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  SegTree seg(N);
  ll M;
  cin >> M;
  for(ll t = 0; t < M; t++) {
    ll c, i, j, k;
    cin >> c;
    if(c == 1) {
      cin >> i >> j >> k;
      seg.update(i, k);
      seg.update(j+1, -k);
    } else {
      cin >> i;
      cout << arr[i] + seg.query(1, i) << '\n';
    }
  }

  return 0;
}