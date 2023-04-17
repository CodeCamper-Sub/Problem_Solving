#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 500500ll
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree() {
    tree.resize(MAX * 4);
    root = 1;
    start = 0;
    end = MAX - 1;
  }
  ll query(ll left, ll right) {
    return query(root, start, end, max(left, 0ll), min(right, MAX - 1));
  }

  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if (start == end) {
      return tree[node] = max(tree[node], value);
    } else {
      ll mid = start + end >> 1;
      return tree[node] = max(update(node * 2, start, mid, target, value), update(node * 2 + 1, mid + 1, end, target, value));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return -INF;
    } else if (left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }
};

ll n, k, d, r[MAX], s;
SegTree seg;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> d;
  for(ll i = 0; i < n; i++) {
    cin >> s;
    ll result = max(seg.query(s - d, s + d), r[s % k]) + 1;
    seg.update(s, result);
    r[s % k] = max(r[s % k], result);
  }

  cout << seg.query(0, MAX - 1) << '\n';
  
  return 0;
}