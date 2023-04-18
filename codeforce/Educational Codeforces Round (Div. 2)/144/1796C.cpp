#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 998244353
typedef long long ll;
using namespace std;

ll tt, l, r, answer;
vector<ll> pow_2;

void init() {
  cin >> l >> r;
  answer = 0;
}
void solve() {
  auto iter = lower_bound(pow_2.begin(), pow_2.end(), r / l);
  if(*iter * l > r) iter--;
  if(iter == pow_2.begin()) {
    cout << 1 << ' ' << r - l + 1 << '\n';
    return;
  }
  ll cnt = iter - pow_2.begin() + 1;
  ll k = *iter;
  answer += r / k - l + 1;
  answer %= MOD;
  k = k * 3 / 2;
  if(k * l <= r) {
    answer += (r / k - l + 1) * (cnt - 1);
    answer %= MOD;
  }
  cout << iter - pow_2.begin() + 1 << ' ' << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  pow_2.push_back(1);
  for(ll i = 1; pow_2.back() * 2 < 1e9; i++) {
    pow_2.push_back(pow_2.back() * 2);
  }
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}