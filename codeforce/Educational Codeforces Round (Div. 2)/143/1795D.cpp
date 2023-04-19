#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, n_cnt, cnt_2, cnt_3;
vector<ll> pow_2, pow_3, fact;

ll power(ll a, ll b) {
  if (b == 0)
    return 1;
  ll temp = power(a, b / 2);
  if (b % 2)
    return temp * temp % MOD * a % MOD;
  else
    return temp * temp % MOD;
}

ll mod_inv(ll a) { return power(a, MOD - 2); }

ll combination(ll n, ll r) {
  return fact[n] * mod_inv(fact[n - r] * fact[r] % MOD) % MOD;
}

void init() {
  cin >> n;
  for (ll i = 0; i < n / 3; i++) {
    vector<ll> e(3);
    cin >> e[0] >> e[1] >> e[2];
    sort(e.begin(), e.end(), greater<>());
    if (e[0] != e[1] && e[1] != e[2]) {
      n_cnt++;
    } else if (e[0] == e[1] && e[1] != e[2]) {
      n_cnt++;
    } else if (e[0] != e[1] && e[1] == e[2]) {
      cnt_2++;
    } else {
      cnt_3++;
    }
  }
}

void solve() {
  ll answer = combination(n / 3, n / 6) % MOD * pow_2[cnt_2] % MOD *
              pow_3[cnt_3] % MOD;
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  pow_2.push_back(1);
  pow_3.push_back(1);
  fact.push_back(1);
  for (ll i = 1; i < 100100; i++) {
    pow_2.push_back(pow_2.back() * 2 % MOD);
    pow_3.push_back(pow_3.back() * 3 % MOD);
    fact.push_back(fact.back() * i % MOD);
  }

  init();
  solve();

  return 0;
}