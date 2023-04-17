#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree{
  vector<ll> tree;
  vector<ll> arr;
  ll start, end, root;

  SegTree() {
    tree = vector<ll>(8000000);
    fill(tree.begin(), tree.end(), 0);
    arr = vector<ll>(2002000);
    fill(arr.begin(), arr.end(), 0);
    start = 1;
    end = 2000000;
    root = 1;
  }

  void update(ll target, ll value) {
    arr[target] += value;
    update(root, start, end, target);
  }
  
  ll query(ll value) {
    return query(root, start, end, value);
  }

  private:
  ll update(ll node, ll start, ll end, ll target){
    if(end < target || target < start) {
      return tree[node];
    } else if(start == end) {
      return tree[node] = arr[target];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target) + update(node * 2 + 1, mid + 1, end, target);
    }
  }

  ll query(ll node, ll start, ll end, ll value) {
    if(start == end) {
      return start;
    }
    ll mid = (start + end) / 2;
    if(value <= tree[node * 2]) {
      return query(node * 2, start, mid, value);
    } else {
      return query(node * 2 + 1, mid + 1, end, value - tree[node * 2]);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;
  SegTree seg;
  for(ll i = 0; i < N; i++) { 
    ll T, X;
    cin >> T >> X;
    if(T == 1) {
      seg.update(X, 1);
    } else {
      ll answer = seg.query(X);
      cout << answer << '\n';
      seg.update(answer, -1);
    }
  }

  return 0;
}