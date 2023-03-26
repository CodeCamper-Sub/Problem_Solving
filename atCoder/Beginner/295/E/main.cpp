#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 2020
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, m, k, a, dp[MAX], cnt, fact[MAX];
vector<ll> v;

ll power(ll a, ll b) { // a ^ b;
    if(b == 0) return 1;
    ll temp = power(a, b / 2);
    if(b % 2) {
        return (temp * temp) % MOD * a % MOD;
    } else {
        return temp * temp % MOD;
    }
}

ll modulo_inverse(ll a) {
    return power(a, MOD - 2);
}

ll combination(ll n, ll r) {
    return fact[n] * modulo_inverse(fact[n - r] * fact[r] % MOD) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fact[0] = 1;
  for(ll i = 1; i < MAX; i++) {
    fact[i] = i * fact[i - 1] % MOD;
  }

  cin >> n >> m >> k;
  for(ll i = 0; i < n; i++) {
    cin >> a;
    if(a) {
        v.push_back(a);
    } else {
        cnt++;
    }
  }

  sort(v.begin(), v.end());
  ll number_of_cases = 0;
  for(ll i = 1; i <= m; i++) {
    auto iter = lower_bound(v.begin(), v.end(), i);
    ll prepared = iter - v.begin(); // 이미 있는 수들 중 i 보다 작은 수들의 개수
    if(iter != v.end() && *iter == i) {    // 이미 i가 있으면 1~i까지 k - 1 - prepared개 뽑고, i ~ m까지 cnt - k + 1 + prepared개 뽑기
        dp[i] = combination(cnt, k - 1 - prepared) * power(i, k - 1 - prepared) % MOD * power(m - i + 1, cnt - k + 1 + prepared) % MOD;
    } else {            // 이미 i가 없으면 1~i까지 i를 적어도 하나 포함해서 k - prepared개 뽑고, i ~ m까지 cnt - k + prepared개 뽑기
        dp[i] = combination(cnt, k - prepared) * (power(i, k - prepared) - power(i - 1, k - prepared)) % MOD * power(m - i + 1, cnt - k + prepared) % MOD;
    }
  }

  ll answer = number_of_cases * modulo_inverse(power(m, cnt)) % MOD;

  cout << answer << '\n';
  
  return 0;
}