#include <bits/stdc++.h>
#define INF 999999999999999999
typedef long long ll;
using namespace std;

const ll swp = 1e12;
const ll rem = 1e12 + 1;

ll tt;
vector<ll> s, left_one;   // left_one: dp[i][1]에서 왼쪽에 남은 1의 개수
string _s;
vector<vector<ll>> dp;

void init() {
  cin >> _s;
  s.clear();
  left_one.clear();
  for(ll i = 0; i < _s.size(); i++) {
    s.push_back(_s[i] - '0');
  }
  dp.assign(s.size(), vector<ll>(3, INF));
  left_one.resize(s.size());
}

void solve() {
  dp[0][s[0]] = 0;
  dp[0][2] = rem;
  if(s[0] == 1) left_one[0] = 1;
  for(ll i = 1; i < s.size(); i++) {
    // 1. 나를 지우기 2. 그대로 있기 3. 왼쪽이랑 바꾸기
    dp[i][0] = min(dp[i][0], dp[i - 1][0] + rem);
    if(s[i] == 0) {
      dp[i][0] = min(dp[i][0], dp[i - 1][2]);
      dp[i][0] = min(dp[i][0], dp[i - 1][0]);
    }


    dp[i][1] = min(dp[i][1], dp[i - 1][1] + rem);   // 1 개수 유지
    if(s[i] == 0 && left_one[i - 1] <= 1) {
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + swp); // 1 개수 유지
    } else if(s[i] == 1) {
      // 1 개수 1개 증가
      dp[i][1] = min(dp[i][1], dp[i - 1][2]);
      dp[i][1] = min(dp[i][1], dp[i - 1][0]);
      dp[i][1] = min(dp[i][1], dp[i - 1][1]);
    }
    if(dp[i][1] == dp[i - 1][1] + rem || dp[i][1] == dp[i - 1][1] + swp || s[i] == 0) {
      left_one[i] = left_one[i - 1];
    } else if(dp[i][1] == dp[i - 1][2] || dp[i][1] == dp[i - 1][0]) {
      left_one[i] = 1;
    } else {
      left_one[i] = left_one[i - 1] + 1;
    }
    
    dp[i][2] = min(dp[i][2], dp[i - 1][2] + rem);
  }

  ll answer = INF;
  for(ll i = 0; i < 3; i++) {
    answer = min(answer, dp[s.size() - 1][i]);
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}