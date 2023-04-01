#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, m;

bool is_prime(ll n) {
    for(ll i = sqrt(n); i >= 1 && m / i <= n; i--) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(ll i = m; ll(sqrt(i)) <= n; i++) {
    if(!is_prime(i)) {
        cout << i << '\n';
        return 0;
    }
  }

  cout << -1 << '\n';
  
  return 0;
}