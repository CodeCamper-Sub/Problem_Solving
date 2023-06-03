#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, answer;
string s;
vector<ll> divisors;
vector<ll> dp;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> s;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i) continue;
    divisors.push_back(i);
    if(i * i != n && i != 1) divisors.push_back(n / i);
  }
  sort(divisors.begin(), divisors.end());
  dp.resize(divisors.size());
  for(ll k = 0; k < divisors.size(); k++) {
    ll d = divisors[k];
    map<ll, ll> m;
    for(ll i = 0; i < s.size(); i++) {
      if(s[i] == '.') {
        m[i % d]++;
      }
    }
    dp[k] = power(2, d - m.size());
  }

  for(ll i = 0; i < divisors.size(); i++) {
    ll cnt = 0;
    for(ll j = i + 1; j < divisors.size(); j++) {
      if(divisors[j] % divisors[i]) continue;
      dp[j] -= dp[i];
      dp[j] = (dp[j] + MOD) % MOD;
    }
  }

  for(ll i = 0; i < divisors.size(); i++) {
    answer += dp[i];
    answer %= MOD;
  }

  cout << answer << '\n';

  
  return 0;
}