#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll k;
vector<ll> n4_cnt; // 10^k보다 작거나 같은 수들 중 4가 들어가지 않는 수들의 개수
deque<ll> answer;
vector<ll> fact, nine_pows;

void init() {
  cin >> k;
  while(answer.size()) answer.pop_front();
}

void solve() {
  for (ll i = 16; i >= 0; i--) {
    answer.push_back(0);
    while (k >= n4_cnt[i]) {
      answer.back() += 1;
      k -= n4_cnt[i];
      if (answer.back() == 4)
        answer.back() += 1;
    }
  }
  while(answer.front() == 0) answer.pop_front();
  while(answer.size()) {
    cout << answer.front();
    answer.pop_front();
  }
  cout << '\n';
}

ll combination(ll n, ll r) { return fact[n] / (fact[n - r] * fact[r]); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fact.push_back(1);
  for (ll i = 1; fact.back() <= ll(1e18); i++) {
    fact.push_back(fact.back() * i);
  }

  nine_pows.push_back(1);
  for (ll i = 1; nine_pows.back() <= ll(1e18); i++) {
    nine_pows.push_back(nine_pows.back() * 9);
  }

  n4_cnt.resize(20);
  n4_cnt[0] = 1;
  for (ll k = 10; k < ll(1e18); k *= 10) {
    ll digit = log10(k) + 0.0005; // 자리수
    n4_cnt[digit] = k;
    for (ll i = 1; i <= digit; i++) {
      n4_cnt[digit] -= combination(digit, i) * nine_pows[digit - i];
    }
  }

  ll tt;
  cin >> tt;
  for (ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}