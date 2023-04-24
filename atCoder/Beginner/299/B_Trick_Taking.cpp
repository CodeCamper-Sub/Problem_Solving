#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, t;
vector<ll> c, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> t;
  c.resize(n);
  r.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> c[i];
  }

  for(ll i = 0; i < n; i++) {
    cin >> r[i];
  }

  ll winner = -1;
  ll maxi = -INF;
  for(ll i = 0; i < n; i++) {
    if(c[i] == t && maxi < r[i]) {
      maxi = r[i];
      winner = i + 1;
    }
  }

  if(winner != -1) {
    cout << winner << '\n';
    return 0;
  }

  for(ll i = 0; i < n; i++) {
    if(c[i] == c[0] && maxi < r[i]) {
      maxi = r[i];
      winner = i + 1;
    }
  }

  cout << winner << '\n';
  
  return 0;
}