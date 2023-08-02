#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

struct Node;

ll n, m, d, id_cnt;
vector<vector<ll>> grid;
vector<ll> binary;
set<Node*> all_nodes;
Node* root;

struct Node {
  ll height, color;
  Node* parent;
  vector<Node*> childs;

  Node(ll color, Node* parent): color(color), parent(parent) {
    height = 0;
    childs.assign(4, NULL);
    all_nodes.insert(this);
  }

  void destory_all_childs() {
    for(Node* child: childs) {
      if(child == NULL) continue;
      child->destory_all_childs();
      all_nodes.erase(child);
      delete child;
    }
    childs.clear();
  }

  bool childs_has_all_same_color() {
    for(ll i = 0; i < 3; i++) {
      if(childs[i]->color != childs[i + 1]->color || childs[i]->color == -1) return false;
    }
    return true;
  }

  ll get_max_child_height() {
    ll maxi = childs[0]->height;
    for(ll i = 1; i < 4; i++) {
      maxi = max(maxi, childs[i]->height);
    }
    return maxi;
  }
};

bool is_same_tree(Node* lhs, Node* rhs) {
  bool result = lhs->height == rhs->height && lhs->color == rhs->color;
  if(!result || lhs->height == 0) return result;
  for(ll i = 0; i < 4; i++) {
    result &= is_same_tree(lhs->childs[i], rhs->childs[i]);
    if(!result) break;
  }
  return result;
}

Node* build_tree(ll y, ll x, ll d, Node* parent) {
  Node* node;
  if(d == 1) {
    node = new Node(grid[y][x], parent);
  } else {
    node = new Node(-1, parent);
    node->childs[0] = build_tree(y, x, d / 2, node);
    node->childs[1] = build_tree(y, x + d / 2, d / 2, node);
    node->childs[2] = build_tree(y + d / 2, x, d / 2, node);
    node->childs[3] = build_tree(y + d / 2, x + d / 2, d / 2, node);
    if(node->childs_has_all_same_color()) {
      node->color = node->childs[0]->color;
      node->destory_all_childs();
      node->height = 0;
    } else {
      node->color = -1;
      node->height = node->get_max_child_height() + 1;
    }
  }
  return node;
}

void compress_quad_tree() {
  for(ll i = root->height - 1; i > 0; i--) {
    vector<Node*> nodes;
    for(Node* n: all_nodes) {
      if(n->height == i) nodes.push_back(n);
    }
    vector<ll> duplicated(nodes.size(), false);
    for(ll j = 0; j < nodes.size(); j++) {
      if(duplicated[j]) continue;
      for(ll k = j + 1; k < nodes.size(); k++) {
        if(is_same_tree(nodes[j], nodes[k])) {
          duplicated[k] = true;
        }
      }
    }
    for(ll j = 0; j < duplicated.size(); j++) {
      if(duplicated[j]) {
        nodes[j]->destory_all_childs();
        all_nodes.erase(nodes[j]);
        delete nodes[j];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  binary.push_back(1);
  while (binary.back() < 128)
    binary.push_back(binary.back() * 2);

  d = *(lower_bound(binary.begin(), binary.end(), max(n, m)));
  grid.resize(d, vector<ll>(d));

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }

  root = build_tree(0, 0, d, NULL);

  cout << all_nodes.size() << ' ';

  compress_quad_tree();

  cout << all_nodes.size();

  return 0;
}