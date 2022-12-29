#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegmentTree {
  vector<ll> tree;
  vector<ll> arr;
  ll start, end;

  SegmentTree(vector<ll> arr) {
    tree = vector<ll>(arr.size() * 4);
    this->arr = arr;
    start = 0;
    end = arr.size() - 1;
    build_tree(1, start, end);
  }
  
  ll query(ll node, ll left, ll right) {
    return query(node, start, end, left, right);
  }

  ll update(ll node, ll target, ll value) {
    return update(node, start, end, target, value);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = arr[start];
    } else if (start > end) {
      return tree[node] = 0;
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(end < left || right < start) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end && start == target) {
      arr[target] = value;
      return tree[node] = arr[target];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value);
    }
  }
};

ll N, M, K, a, b, c;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> K;
  arr = vector<ll>(N);
  for(ll i = 0; i < N; i++) {
    cin >> arr[i];
  }
  SegmentTree seg = SegmentTree(arr);

  for(ll i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if(a == 1) {
      seg.update(1, b - 1, c);
    } else {
      cout << seg.query(1, b - 1, c - 1) << '\n';
    }
  }

  return 0;
}