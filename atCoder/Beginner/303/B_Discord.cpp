#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<ll>> adj;
vector<vector<ll>> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n;
  a.resize(n, vector<ll>(m));
  adj.resize(m + 1, vector<ll>(m + 1, 0));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> a[i][j];
      if(j > 0) {
        adj[a[i][j]][a[i][j - 1]] = 1;
        adj[a[i][j - 1]][a[i][j]] = 1;
      }
    }
  }
  ll answer = 0;
  for(ll i = 1; i <= m; i++) {
    for(ll j = i + 1; j <= m; j++) {
      if(adj[i][j] == 0) answer++;
    }
  }

  cout << answer << '\n';
  
  return 0;
}