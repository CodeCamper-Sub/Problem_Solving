//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll n, answer, local_answer;
ll grid[20][20];
char c;

int dy[10] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[10] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> c;
      grid[i][j] = c - '0';
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int d = 0; d < 8; d++) {
        ll digit = pow(10, n - 1);
        local_answer = 0;
        for(int k = 0; k < n; k++) {
          ll now_y = (i + dy[d] * k) % n;
          now_y = now_y <= 0 ? now_y + n : now_y;
          ll now_x = (j + dx[d] * k) % n;
          now_x = now_x <= 0 ? now_x + n : now_x;
          local_answer += digit * grid[now_y][now_x];
          digit /= 10;
        }
        answer = max(answer, local_answer);
      }
    }
  }
  cout << answer << '\n';
  
  return 0;
}

