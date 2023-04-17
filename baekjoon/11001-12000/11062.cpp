#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, answer;
vector<ll> card;
vector<vector<vector<ll>>> dp;  // i의 턴일 때, 왼쪽에서 j개, 오른쪽에서 k개 가져갔을 때 근우가 얻을 수 있는 최대 점수

ll go(ll left, ll right, ll turn) {
  if(left + right >= n) return 0;
  if(dp[turn][left][right] != -1) return dp[turn][left][right];
  if(turn == 0) { // 근우의 턴
    dp[turn][left][right] = max(card[left] + go(left + 1, right, 1 - turn), card[n - right - 1] + go(left, right + 1, 1 - turn));
    return dp[turn][left][right];
  } else {
    dp[turn][left][right] = min(go(left + 1, right, 1 - turn), go(left, right + 1, 1 - turn));
    return dp[turn][left][right];
  }
}

void init() {
  cin >> n;
  answer = -INF;
  card.resize(n);
  for(ll i = 0; i < n; i++) cin >> card[i];
  dp.assign(2, vector<vector<ll>>(n, vector<ll>(n, -1)));
}

void solve() {
  cout << go(0, 0, 0) << '\n';
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