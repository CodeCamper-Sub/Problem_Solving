#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, x;
vector<vector<ll>> e, inv_e;
vector<ll> visited;

void dfs(ll now, ll& cnt, vector<vector<ll>>& e) {
  cnt++;
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      dfs(next, cnt, e);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> x;
  e.resize(n + 1);
  inv_e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    e[b].push_back(a);
    inv_e[a].push_back(b);
  }

  visited.assign(n + 1, false);
  ll upper = 0, lower = 0;

  dfs(x, upper, e);

  visited.assign(n + 1, false);
  dfs(x, lower, inv_e);
  
  cout << upper << ' ' << n - lower + 1 << '\n';
  
  return 0;
}