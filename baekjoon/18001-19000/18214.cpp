#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9 + 7)
typedef int ll;
using namespace std;

ll n, m, answer;
vector<ll> books;
map<tuple<ll, ll, ll, ll>, ll> dp;
map<tuple<ll, ll, ll, ll>, ll> inQ;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  books.resize(n);
  for(ll& b: books) cin >> b;

  queue<tuple<ll, ll, ll, ll>> q;
  dp[{0, 0, 0, 0}] = 1;
  q.push({0, 0, 0, 0});

  answer = 0;
  while(q.size()) {
    auto [k_1, k_2, t_1, t_2] = q.front();
    q.pop();
    if(k_1 + k_2 == n) {
      answer += dp[{k_1, k_2, t_1, t_2}];
      answer %= MOD;
      continue;
    }
    ll now = books[k_1 + k_2];
    if(k_1 < m && now > t_1) {
      dp[{k_1 + 1, k_2, now, t_2}] += dp[{k_1, k_2, t_1, t_2}];
      dp[{k_1 + 1, k_2, now, t_2}] %= MOD;
      if(inQ.count({k_1 + 1, k_2, now, t_2}) == 0) {
        inQ[{k_1 + 1, k_2, now, t_2}]++;
        q.push({k_1 + 1, k_2, now, t_2});
      }
    }
    if(k_2 < m && now > t_2) {
      dp[{k_1, k_2 + 1, t_1, now}] += dp[{k_1, k_2, t_1, t_2}];
      dp[{k_1, k_2 + 1, t_1, now}] %= MOD;
      if(inQ.count({k_1, k_2 + 1, t_1, now}) == 0) {
        inQ[{k_1, k_2 + 1, t_1, now}]++;
        q.push({k_1, k_2 + 1, t_1, now});
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}