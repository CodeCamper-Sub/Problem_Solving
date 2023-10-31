#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll N;
ll dp[300][100000];
ll arr[500][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(ll i = 1; i <= N; i++){
    cin >> arr[i][0] >> arr[i][1];
  }
  fill(&dp[0][0], &dp[299][99999], INT_MAX);
  dp[1][0] = arr[1][1];
  dp[1][arr[1][0]] = 0;
  for(ll i = 2; i <= N; i++){
    for(ll j = 0; j <= 99999; j++){
      if(dp[i-1][j] != INT_MAX){
        dp[i][j+arr[i][0]] = min(dp[i-1][j], dp[i][j+arr[i][0]]);
        dp[i][j] = min(dp[i-1][j]+arr[i][1], dp[i][j]);
      }
    }
  }
  ll answer = INT_MAX;

  for(ll i = 0 ; i <= 99999;i ++){
    ll tt = 0;
    tt = max(dp[N][i], i);
    answer = min(answer , tt);
  }
  cout << answer << "\n";
  
  
  return 0;
}