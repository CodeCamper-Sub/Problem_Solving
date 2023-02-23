#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, k, fact[1001000], a[200200], answer, numerator, denominator, reverse_denominator;
vector<ll> c;

tuple<ll, ll, ll> xGCD(ll a, ll b) {
  if(b == 0) return {a, 1, 0};
  tuple<ll, ll, ll> result = xGCD(b, a % b);
  ll g, x, y;
  g = get<0>(result);
  x = get<2>(result);
  y = get<1>(result) - (a / b) * get<2>(result);
  return {g, x, y};
}

ll reverse_modulo(ll a) {
  ll ret = 0;
  for(ll k = 0; k <= (a * MOD - 2) / MOD + 1; k++) {
    if((1 + k * MOD) % a == 0) {
      ret = (1 + k * MOD) / a;
      break;
    }
  }
  return ret;
}

ll combi(ll n, ll k) {
    numerator = fact[n];
    denominator = (fact[n-k] * fact[k]) % MOD;
    reverse_denominator = get<1>(xGCD(denominator, MOD));
    reverse_denominator = reverse_denominator < 0 ? reverse_denominator + MOD : reverse_denominator;
    return (numerator * reverse_denominator) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    fact[0] = 1;

    for(ll i = 1; i < 1001000; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(ll i = 0; i < a[0]; i++) {
        c.push_back(i);
    }

    for(ll i = 0; i < n - 1; i++) {
        if(a[i] + 1 < a[i+1]) {
            for(ll j = a[i] + 1; j < a[i+1]; j++) {
                c.push_back(j);
            }
        }
    }

    c.push_back(a[n-1] + 1);

    while(c.size() <= k) {
        c.push_back(c.back() + 1);
    }

    for(ll i = 0; i <= k; i++) {
        if(c[i] == 0) continue;
        answer += combi(c[i] + k - i - 1, k - i);
        answer %= MOD;
    }

    cout << answer << '\n';
    

    return 0;
}