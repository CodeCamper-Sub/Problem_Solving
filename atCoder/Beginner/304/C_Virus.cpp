#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, d;
ll a, b, x, y;

vector<pair<ll, ll>> p;
vector<vector<ll>> e;
vector<ll> visited;

void dfs(ll now) {
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      dfs(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> d;
  p.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  e.resize(n + 1);
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      if(i == j) continue;
      if((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second) <= d * d) {
        e[i].push_back(j);
      }
    }
  }

  visited.assign(n, false);
  visited[0] = true;
  dfs(0);
  for(ll i = 0; i < n; i++) {
    if(visited[i]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  
  return 0;
}