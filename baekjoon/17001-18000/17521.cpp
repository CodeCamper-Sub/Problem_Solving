#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;


ll N, W;
ll dp[30][2][2];
ll arr[30];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> W;
  for(ll i = 1; i <= N; i++){
    cin >> arr[i];
  }
  dp[1][0][0] = W/arr[1];
  dp[1][0][1] = W-(W/arr[1])*arr[1];
  dp[1][1][0] = 0;
  dp[1][1][1] = W;
  ll answer = W;
  for(ll i = 2; i<= N; i++){
    ll maxt = 0;
    ll anst = 0; 
    for(ll j = 1; j < i ; j++){
      maxt = max(maxt , dp[j][1][1]);
      anst = max(anst, dp[j][0][0] * arr[i] + dp[j][0][1]);
    }
    dp[i][0][0] = maxt/arr[i];
    dp[i][0][1] = maxt - (maxt/arr[i])*arr[i];
    dp[i][1][0] = 0;
    dp[i][1][1] = anst;
    answer = max(answer, anst);
  }
  
  cout << answer << "\n";
  
  
  return 0;
}