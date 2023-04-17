#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll gcd(ll, ll);
ll big_remainder(string s, ll k);

ll N, K, remainders[20], dp[1<<15][110], digit_remainders[55];
string s[20];

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

// O(100);
ll big_remainder(string s, ll k) {
  vector<ll> k_multiples;
  for(ll i = 1; i <= 9; i++) {
    k_multiples.push_back(k * i);
  }
  ll now_s = 0;
  for(ll i = 0; i < s.size(); i++) {
    now_s *= 10;
    now_s += s[i] - '0';
    if(now_s < k) continue;
    auto iter = lower_bound(k_multiples.begin(), k_multiples.end(), now_s);
    if(*iter == now_s) {
      now_s -= *iter;
    } else {
      now_s -= *(iter - 1);
    }
  }
  return now_s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> s[i];
  }
  cin >> K;
  for(ll i = 0; i < N; i++) {
    remainders[i] = big_remainder(s[i], K);
  }
  string digit_string = "1";
  for(ll i = 0; i <= 50; i++) {
    digit_remainders[i] = big_remainder(digit_string, K);
    digit_string += '0';
  }

  dp[0][0] = 1;
  for(ll status = 0; status < (1 << N)-1; status++) {
    for(ll j = 0; j < N; j++) {
      // j번째 수를 i상태의 순열 뒤에 덧붙이려고 함
      if(status & (1 << j)) continue;
      ll next_status = status | (1 << j);
      for(ll k = 0; k < K; k++) {
        if(dp[status][k] == 0) continue;
        // k가 현재 나머지
        ll next_remainder = k * digit_remainders[s[j].size()] + remainders[j];
        next_remainder %= K;
        dp[next_status][next_remainder] += dp[status][k];
      }
    }
  }

  ll factorial = 1;
  for(ll i = 1; i <= N; i++) factorial *= i;
  ll g = gcd(dp[(1 << N) - 1][0], factorial);
  cout << dp[(1 << N) - 1][0] / g << '/' << factorial / g << '\n';

  return 0;
}