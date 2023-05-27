#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<map<ll, ll>> e;
vector<ll> ind;
vector<pair<ll, ll>> edges;
vector<ll> visited, answers;

bool can_cut(ll u, ll v) {
  ll op_u, op_v;
  for(auto [next, _]: e[u]) {
    if(next != v) op_u = next;
  }
  for(auto [next, _]: e[v]) {
    if(next != u) op_v = next;
  }

  if((ind[op_u] == 1 && ind[op_v] == 2) || (ind[op_u] == 2 && ind[op_v] == 1) || (ind[op_u] == 2 && ind[op_v] == 2)) return false;
  return true;
}

void dfs(ll now, bool& is_star, ll& cnt) {
  cnt += 1;
  if(ind[now] > 2) is_star = true;
  for(auto [next, _]: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      dfs(next, is_star, cnt);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n + 1);
  ind.resize(n + 1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u][v]++;
    e[v][u]++;
    ind[u]++;
    ind[v]++;
    edges.push_back({u, v});
  }

  for(auto [u, v]: edges) {
    if(ind[u] != 2 || ind[v] != 2) continue;
    if(can_cut(u, v)) { 
      e[u].erase(v);
      e[v].erase(u);
      ind[u]--;
      ind[v]--;
    }
  }

  visited.assign(n + 1, false);
  for(ll i = 1; i <= n; i++) {
    if(!visited[i]) {
      ll cnt = 0;
      bool is_star = false;
      visited[i] = true;
      dfs(i, is_star, cnt);
      if(!is_star) {
        while(cnt) {
          answers.push_back(2);
          cnt -= 3;
        }
      } else {
        answers.push_back(cnt - 1);
      }
    }
  }
  sort(answers.begin(), answers.end());
  for(auto a: answers) {
    cout << a << ' ';
  }

  
  return 0;
}