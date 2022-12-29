#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct SegmentTree {
  vector<ll> tree;
  vector<ll> arr;
  ll start, end;
  SegmentTree(vector<ll> arr) {
    tree = vector<ll>(arr.size() * 4);
    this->arr = arr;
    start = 1;
    end = arr.size() - 1;
    build_tree(1, start, end);
  }

  public: 
  ll query(ll left, ll right){
    return query(1, start, end, left, right);
  }

  ll update(ll target, ll value) {
    return update(1, start, end, target, value);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      tree[node] = build_tree(node * 2, start, mid) * build_tree(node * 2 + 1, mid + 1, end);
      tree[node] %= MOD;
    }
    return tree[node];
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(end < left || right < start) {
      return 1;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right) % MOD;
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      arr[target] = value;
      return tree[node] = arr[target];
    } else {
      ll mid = (start + end) / 2;
      tree[node] = update(node * 2, start, mid, target, value) * update(node * 2 + 1, mid + 1, end, target, value);
      tree[node] %= MOD;
      return tree[node];
    }
  }
};

ll N, M, K, a, b, c;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> K;
  arr = vector<ll>(N + 1);
  for(ll i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  SegmentTree seg = SegmentTree(arr);
  for(ll i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if(a == 1) {
      seg.update(b, c);
    } else {
      cout << seg.query(b, c) << '\n';
    }
  }

  return 0;
}