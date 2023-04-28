#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;
vector<ll> dp;  // dp[i] 길이가 i인 100000.. 형태의 문자열을 전부 0으로 만드는 비용
                // 이 비용은 길이가 i인 0000.. 형태의 문자열을 1000..으로 만드는 비용과 동일하다.
                // dp[i] = 2 * dp[i - 1] + 1

void init() {
  cin >> s;
}

ll make_all_zero(ll);
ll make_one(ll);

ll make_all_zero(ll now) {
  while(now < s.size() && s[now] == '0') now++;
  if(now == s.size()) return 0;
  if(now == s.size() - 1) return 1;
  if(s[now + 1] == '0') return make_one(now + 1) + 1 + dp[s.size() - now - 1];
  else return make_all_zero(now + 2) + 1 + dp[s.size() - now - 1];
}

ll make_one(ll now) {
  if(now == s.size() - 1) return 1;
  if(s[now + 1] == '0') return make_one(now + 1) + 1 + dp[s.size() - now - 1];
  else return make_all_zero(now + 2) + 1 + dp[s.size() - now - 1];
}

void solve() {
  cout << make_all_zero(0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  dp.resize(40);
  for(ll i = 1; i < 40; i++) {
    dp[i] = 2 * dp[i - 1] + 1;
  }


  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}