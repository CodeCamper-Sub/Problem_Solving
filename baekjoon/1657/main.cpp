#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
ll dp[200][1 << 15];
ll score[5][5];
ll grid[20][20];

void init() {
  score[0][0] = 10;
  score[0][1] = 8;
  score[0][2] = 7;
  score[0][3] = 5;
  score[0][4] = 1;
  
  score[1][1] = 6;
  score[1][2] = 4;
  score[1][3] = 3;
  score[1][4] = 1;

  score[2][2] = 3;
  score[2][3] = 2;
  score[2][4] = 1;

  score[3][3] = 2;
  score[3][4] = 1;

  score[4][4] = 0;

  for(ll i = 0; i < 5; i++) {
    for(ll j = 0; j < i; j++) {
      score[i][j] = score[j][i];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  init();
  cin >> n >> m;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++){ 
      char c;
      cin >> c;
      if(c == 'F') {
        grid[i][j] = 4;
      } else {
        grid[i][j] = c - 'A';
      }
    }
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      ll idx = i * m + j;
      for(ll status = 0; status < (1 << m); status++) {
        if(status & (1 << 0)) {
          // 현재 칸이 차 있을 때
          ll next_status = status >> 1;
          dp[idx + 1][next_status] = max(dp[idx + 1][next_status], dp[idx][status]);
        } else {
          // 현재 칸이 비어 있을 때

          // 안 채우고 넘기기
          ll next_status = status >> 1;
          dp[idx + 1][next_status] = max(dp[idx + 1][next_status], dp[idx][status]);

          if((status & (1 << 1)) == 0 && j < m - 1) {
            // 가로로 채우기
            ll next_status = status | (1 << 0) | (1 << 1);
            next_status >>= 1;
            dp[idx + 1][next_status] = max(dp[idx + 1][next_status], dp[idx][status] + score[grid[i][j]][grid[i][j+1]]);
          }
          if(i < n - 1) {
            // 세로로 채우기
            ll next_status = status | (1 << 0) | (1 << m);
            next_status >>= 1;
            dp[idx + 1][next_status] = max(dp[idx + 1][next_status], dp[idx][status] + score[grid[i][j]][grid[i+1][j]]);
          }
        }
      }
    }
  }

  cout << dp[n * m][0] << '\n';
  
  return 0;
}