#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Node;
class Compare;

struct Node {
  ll imp, ssize, parent, index;

  class Compare {
      public:
      bool operator() (Node* a, Node* b) {
        if(a->ssize != b->ssize) {
          return a->ssize < b->ssize;
        } else {
          return a->index > b->ssize;
        }
      }
  };

  priority_queue<Node*, vector<Node*>, Compare> childs;
};

ll n, m, t, x, u, v;
vector<Node> nodes;
vector<vector<ll>> e;
vector<ll> a, visited;

pair<ll, ll> dfs(ll now, ll parent) {
  nodes[now].index = now;
  nodes[now].imp = a[now];
  nodes[now].ssize = 1;
  nodes[now].parent = parent;
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      auto [imp, ssize] = dfs(next, now);
      nodes[now].childs.push(&nodes[next]);
      nodes[now].imp += imp;
      nodes[now].ssize += ssize;
    }
  }
  return {nodes[now].imp, nodes[now].ssize};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  e.resize(n + 1);
  nodes.resize(n + 1);
  a.resize(n + 1);
  visited.assign(n + 1, false);
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for(ll i = 0; i < n - 1; i++) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  visited[1] = true;
  dfs(1, -1);

  while(m--) {
    cin >> t >> x;
    if(t == 1) {
      cout << nodes[x].imp << '\n';
    } else if(nodes[x].childs.size()) {
      Node* heavy_child = nodes[x].childs.top();
      nodes[x].childs.pop();
      swap(heavy_child->childs, nodes[x].childs);
      ll next_imp = nodes[x].imp - heavy_child->imp;
      ll next_ssize = nodes[x].ssize - heavy_child->ssize;
      heavy_child->imp = nodes[x].imp;
      heavy_child->ssize = nodes[x].ssize;
      nodes[x].imp = next_imp;
      nodes[x].ssize = next_ssize;
      heavy_child->childs.push(&nodes[x]);
    }
  }
  
  return 0;
}