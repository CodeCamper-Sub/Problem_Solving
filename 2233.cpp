#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, x, y, cnt;
string s;
vector<vector<ll>> e;
vector<ll> id, parent, level;

void dfs(ll now) {
  for(ll next: e[now]) {
    if(level[next] == -1) {
      level[next] = level[now] + 1;
      dfs(next);
    }
  }
}

ll set_level(ll a, ll to_level) {
  while(level[a] != to_level) {
    a = parent[a];
  }
  return a;
}

ll lca(ll a, ll b) {
  a = set_level(a, min(level[a], level[b]));
  b = set_level(b, min(level[a], level[b]));
  while(a != b) {
    a = parent[a];
    b = parent[b];
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> s >> x >> y;
  x--; y--;
  e.resize(n + 1);
  parent.resize(n + 1);
  id.resize(s.size());
  level.assign(n + 1, -1);
  ll now = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '0') {
      ll next = ++cnt;
      parent[next] = now;
      e[now].push_back(next);
      now = next;
      id[i] = now;
    } else {
      id[i] = now;
      now = parent[now];
    }
  }
  
  level[0] = 0;
  dfs(0);

  ll a = id[x];
  ll b = id[y];
  ll c = lca(a, b);
  for(ll i = 0; i < s.size(); i++) {
    if(id[i] == c) {
      cout << i + 1 << ' ';
    }
  }
  
  return 0;
}