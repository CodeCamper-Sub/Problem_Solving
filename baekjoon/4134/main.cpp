#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, tt;

void solve() {
  cin >> n;
  if(n == 0 || n == 1) n = 2;
  while(true) {
    bool is_prime = true;
    for(ll i = 2; i * i <= n; i++) {
      if(n % i == 0) {
        is_prime = false;
        break;
      }
    }
    if(is_prime) {
      cout << n << '\n';
      break;
    }
    n++;
  }
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    solve();
  }

  return 0;
}