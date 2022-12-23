#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N;
string s[20];
vector<ll> e[20];
ll dp[20][1<<20]; // node에 status로 오면 지는지(0), 이기는지(1)

ll dfs(ll node, ll status) {
  if(dp[node][status] != -1) return dp[node][status];
  if(status == (1 << N) - 1) return dp[node][status] = 1;
  bool cant_go = true;
  bool lose = true;
  for(ll i = 0; i < e[node].size(); i++){
    ll next = e[node][i];
    if(!(status & (1 << next))) {
      cant_go = false;
      if(dfs(next, status | (1 << next)) == 0) {
        lose = false;
      }
    }
  }
  if(cant_go) return dp[node][status] = 1;
  if(lose) {
    return dp[node][status] = 0;
  } else {
    return dp[node][status] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) 
    cin >> s[i];

  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < (1 << 20); j++) {
      dp[i][j] = -1;
    }
  }

  for(ll i = 0; i < N; i++) {
    for(ll j = 0; j < N; j++) {
      if(i == j)
        continue;
      if(s[i].back() == s[j][0]) {
        e[i].push_back(j);
      }
    }
  }

  bool first_lose = true;
  for(ll i = 0; i < N; i++) {
    if(dfs(i, 0 | (1 << i)) == 1) {
      first_lose = false;
      break;
    }
  }
  if(first_lose) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
  
  return 0;
}