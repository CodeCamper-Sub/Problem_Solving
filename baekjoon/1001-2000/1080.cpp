#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<ll>> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  a.assign(n, vector<ll>(m));
  b.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      b[i][j] = c - '0';
    }
  }

  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      if(a[i][j] ^ b[i][j] && i < n - 2 && j < m - 2) {
        for(ll k = 0; k < 3; k++) {
          for(ll l = 0; l < 3; l++) {
            a[i + k][j + l] ^= 0 ^ 1;
          }
        }
        answer++;
      }
    }
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      if(a[i][j] ^ b[i][j]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}