#include <bits/stdc++.h>
#define INF 999999999999
#define MOD ll(1e9+7)
typedef long long ll;
using namespace std;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  else if(b == 1) return a;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

ll mod_inv(ll a) {
  return power(a, MOD - 2) % MOD;
}

ll m, answer, n, s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m;
  while(m--) {
    cin >> n >> s;
    answer += s * mod_inv(n);
    answer %= MOD;
  }

  cout << answer << '\n';

  
  return 0;
}