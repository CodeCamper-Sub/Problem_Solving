#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<vector<ll>> e;
vector<ll> wolves, sheeps;

ll dfs(ll now, ll parent) {
  ll result = sheeps[now];
  for(ll next: e[now]) {
    if(next == parent) continue;
    result += dfs(next, now);
  }

  if(wolves[now]) {
    result = max(0ll, result - wolves[now]);
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n + 1);
  wolves.resize(n + 1);
  sheeps.resize(n + 1);
  for(ll i = 2; i <= n; i++) {
    char t;
    ll a, p;
    cin >> t >> a >> p;
    if(t == 'W') {
      wolves[i] = a;
    } else {
      sheeps[i] = a;
    }
    e[i].push_back(p);
    e[p].push_back(i);
  }

  ll answer = dfs(1, -1);

  cout << answer << '\n';
  
  
  return 0;
}