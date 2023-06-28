#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

struct Node;

ll n;
vector<vector<ll>> e;
Node* tree;

struct Node {
  ll height = 0;
  Node *left = NULL, *right = NULL;

  void build_tree(ll now, ll parent) {
    for(ll next: e[now]) {
      if(next == parent) continue;
      if(left == NULL) {
        left = new Node();
        left->build_tree(next, now);
        height = max(height, left->height + 1);
      } else {
        right = new Node();
        right->build_tree(next, now);
        height = max(height, right->height + 1);
      }
    }
  }

  void rebalance() {
    if(left != NULL) left->rebalance();
    if(right != NULL) right->rebalance();
    ll left_height = 0, right_height = 0;
    if(left != NULL) left_height = left->height + 1;
    if(right != NULL) right_height = right->height + 1;
    if(abs(left_height - right_height) > 1) {
      height = min(left_height, right_height) + 1;
      if(left != NULL) left->height = min(left->height, height - 1);
      if(right != NULL) right->height = min(right->height, height - 1);
    } else {
      height = max(left_height, right_height);
    }
  }

  ll calc_cnt(ll max_height) {
    ll result = 1;
    if(height == 0 || max_height == 0) return result;
    if(left != NULL) result += left->calc_cnt(min(height - 1, max_height - 1));
    if(right != NULL) result += right->calc_cnt(min(height - 1, max_height - 1));
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n + 1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  tree = new Node();
  tree->build_tree(1, -1);

  tree->rebalance();
  cout << n - tree->calc_cnt(INF) << '\n';

  return 0;
}