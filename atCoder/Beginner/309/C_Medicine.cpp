#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, k, sum;
map<ll, ll> pres;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  for(ll i = 0; i < n; i++) {
    ll key, value;
    cin >> key >> value;
    pres[key] += value;
    sum += value;
  }

  if(sum <= k) {
    cout << 1 << '\n';
    return 0;
  }

  for(auto [key, value]: pres) {
    sum -= value;
    if(sum <= k) {
      cout << key + 1 << '\n';
      return 0;
    }
  }

  
  return 0;
}