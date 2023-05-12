#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll a, b, n, answer;
vector<ll> primes;

void factorize(ll n) {
  for(ll i = 2; i * i <= n; i++) {
    if(n % i) continue;
    primes.push_back(i);
    while(n % i == 0) {
      n /= i;
    }
  }
  if(n > 1) {
    primes.push_back(n);
  }
}

void backtracking(ll now, ll cnt, ll LCM) {
  if(now == primes.size()) {
    ll aa = (a / LCM + (a % LCM ? 1 : 0)) * LCM;
    if(cnt % 2 == 0) {
      answer += (b - aa) / LCM + 1;
    } else {
      answer -= (b - aa) / LCM + 1;
    }
    return;
  }
  backtracking(now + 1, cnt, LCM);
  backtracking(now + 1, cnt + 1, lcm(LCM, primes[now]));
}

void init() {
  cin >> a >> b >> n;
  primes.clear();
  answer = 0;
}

void solve() {
  factorize(n);
  backtracking(0, 0, 1);
  cout << answer << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    cout << "Case #" << T << ": ";
    init();
    solve();
  }
  return 0;
}