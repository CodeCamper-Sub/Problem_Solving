#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

unordered_map<ll, ll> mp;
ll n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mp[x]++;
  }
  cin >> m;
  while(m--) {
    ll x;
    cin >> x;
    cout << (mp.count(x) > 0 ? '1' : '0') << ' ';
  }
  
  return 0;
}