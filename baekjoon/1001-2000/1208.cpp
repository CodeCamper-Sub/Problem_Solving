#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

map<ll, ll> m;
ll n, s, a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> s;

  m[0]++;
  for(ll i = 0; i < n; i++) {
    cin >> a;
    map<ll, ll> batch;
    for(auto [key, value]: m) {
      batch[key + a] += value;
    }
    for(auto [key, value]: batch) {
      m[key] += value;
    }
  }

  m[0]--;
  cout << m[s] << '\n';
  
  return 0;
}