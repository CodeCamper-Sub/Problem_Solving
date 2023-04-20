#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<vector<ll>> a, b;

void rotate() {
  vector<vector<ll>> result;
  result.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      result[i][j] = a[n - 1 - j][i];
    }
  }
  a = result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.assign(n, vector<ll>(n));
  b.assign(n, vector<ll>(n));

  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> a[i][j];
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> b[i][j];

  ll tt = 4;
  while(tt--) {
    bool is_valid = true;
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        if(a[i][j] == 1 && b[i][j] == 0) {
          is_valid = false;
          break;
        }
      }
    }

    if(is_valid) {
      cout << "Yes\n";
      return 0;
    }
    rotate();
  }

  cout << "No\n";
  
  return 0;
}