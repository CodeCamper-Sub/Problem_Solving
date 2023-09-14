#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

map<ll, ll> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  for(ll i = 0; i < 5; i++) {
    ll x;
    cin >> x;
    m[x]++;
  }

  for(auto [key, value]: m) {
    if(value % 2) {
      cout << key << '\n';
    }
  }
  
  return 0;
}