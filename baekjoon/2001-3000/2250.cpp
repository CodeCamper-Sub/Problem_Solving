#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct Node {
  ll num, size;
  Node* left = NULL;
  Node* right = NULL;
};

ll n, root;
vector<vector<ll>> e;
vector<ll> ind, leftmost, rightmost;
Node* tree;

Node* build_tree(ll now) {
  Node* node = new Node();
  node->num = now;
  node->size = 1;
  if(e[now][0] != -1) {
    node->left = build_tree(e[now][0]);
    node->size += node->left->size;
  }
  if(e[now][1] != -1) {
    node->right = build_tree(e[now][1]);
    node->size += node->right->size;
  }
  return node;
}

void calculate(Node* now, ll level, ll left) {
  ll now_col;
  if(now->left == NULL) {
    now_col = left;
  } else {
    now_col = left + now->left->size;
  }
  leftmost[level] = min(leftmost[level], now_col);
  rightmost[level] = max(rightmost[level], now_col);
  if(now->left != NULL) {
    calculate(now->left, level + 1, left);
  }
  if(now->right != NULL) {
    calculate(now->right, level + 1, now_col + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.assign(n + 1, vector<ll>());
  ind.assign(n + 1, 0);
  for(ll i = 0; i < n; i++) {
    ll u, l, r;
    cin >> u >> l >> r;
    e[u].push_back(l);
    e[u].push_back(r);
    if(l > 0) ind[l]++;
    if(r > 0) ind[r]++;
  }

  for(ll i = 1; i <= n; i++) {
    if(ind[i] == 0) {
      root = i;
      break;
    }
  }

  tree = build_tree(root);
  leftmost.assign(n + 1, INF);
  rightmost.assign(n + 1, -INF);
  calculate(tree, 0, 0);
  ll answer = 0, maxi = -INF;
  for(ll i = 0; i < leftmost.size(); i++) {
    if(leftmost[i] == INF || rightmost[i] == -INF) break;
    if(maxi < rightmost[i] - leftmost[i] + 1) {
      maxi = rightmost[i] - leftmost[i] + 1;
      answer = i + 1;
    }
  }

  cout << answer << ' ' << maxi << '\n';
  
  return 0;
}