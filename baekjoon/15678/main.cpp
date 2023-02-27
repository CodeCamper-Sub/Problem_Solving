#include <bits/stdc++.h>
#define INF 99999999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  vector<ll> dp;
  ll root, start, end;
  SegTree(ll n) {
    tree = vector<ll>(n * 4);
    dp = vector<ll>(n);
    fill(dp.begin(), dp.end(), -INF);
    root = 1;
    start = 0;
    end = n - 1;
    build_tree(root, start, end);
  }
  public:
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = dp[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = max(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
    }
  }
  
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return -INF;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      dp[start] = value;
      return tree[node] = dp[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = max(update(node * 2, start, mid, target, value), update(node * 2 + 1, mid + 1, end, target, value));
    }
  }
};

ll n, d, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> d;
  
  SegTree seg(n);

  for(ll i = 0; i < n; i++) {
    cin >> k;
    if(i > 0) {
      ll left = max(0ll, i - d);
      ll right = i - 1;
      ll maximum = max(seg.query(left, right), 0ll);
      seg.update(i, maximum + k);
    } else {
      seg.update(0, k);
    }
  }

  cout << seg.query(0, n - 1) << '\n';
  
  return 0;
}