#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
ll dp[10010][10];
string s_str, e_str;
vector<ll> s, e;
queue<tuple<ll, ll>> q; // {몇 번 돌아가 있는 상태인지, 거리}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s_str;
  cin >> e_str;

  for(ll i = 0; i < n; i++) {
    s.push_back(s_str[i]-'0');
    e.push_back(e_str[i]-'0');
  }

  fill(&dp[0][0], &dp[10009][10], INF);

  q.push({0, 0});
  for(ll i = 0; i < n; i++) {
    ll tt = q.size();
    while(tt--) {
      auto [now, distance] = q.front();
      q.pop();
      if(distance > dp[i][now]) continue;
      ll rotated_s = (s[i] + now) % 10;
      if(rotated_s < e[i]) {
        ll next = (now + e[i] - rotated_s) % 10;
        if(dp[i+1][next] > distance + e[i] - rotated_s) {
          dp[i+1][next] = distance + e[i] - rotated_s;
          q.push({next, distance + e[i] - rotated_s});
        }
        next = now;
        if(dp[i+1][next] > distance + 10 + rotated_s - e[i]) {
          dp[i+1][next] = distance + 10 + rotated_s - e[i];
          q.push({next, distance + 10 + rotated_s - e[i]});
        }
      } else if(rotated_s > e[i]) {
        ll next = (now + 10 + e[i] - rotated_s) % 10;
        if(dp[i+1][next] > distance + 10 + e[i] - rotated_s) {
          dp[i+1][next] = distance + 10 + e[i] - rotated_s;
          q.push({next, distance + 10 + e[i] - rotated_s});
        }
        next = now;
        if(dp[i+1][next] > distance + rotated_s - e[i]) {
          dp[i+1][next] = distance + rotated_s - e[i];
          q.push({next, distance + rotated_s - e[i]});
        }
      } else {
        ll next = now;
        if(dp[i+1][next] > distance) {
          dp[i+1][next] = distance;
          q.push({next, distance});
        }
      }
    }
  }

  ll answer = INF;
  for(ll i = 0; i < 10; i++) {
    answer = min(answer, dp[n][i]);
  }

  cout << answer << '\n';
  
  return 0;
}