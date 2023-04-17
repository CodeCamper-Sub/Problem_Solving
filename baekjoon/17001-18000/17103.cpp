#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, sieve[1001000];

void solve() {
  cin >> n;

  ll answer = 0;
  for(ll i = 2; i <= n / 2; i++) {
    if(sieve[i] == i && sieve[n - i] == n - i) answer++;
  }
  #ifdef DEBUG
  cout << "\nAns: ";
  #endif
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 2; i <= 1000000; i++) {
    if(sieve[i] == 0) {
      for(ll j = 1; i * j <= 1000000; j++) {
        sieve[i * j] = i;
      }
    }
  }

  cin >> tt;
  while(tt--) {
    solve();
  }
  
  return 0;
}