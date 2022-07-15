//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll h[4], w[4], answer;

bool is_valid(ll grid[][4]) {
  for(ll i = 1; i <= 3; i++) {
    for(ll j = 1; j <= 3; j++) {
      if(grid[i][j] <= 0) {
        return false;
      }
    }
  }
  if(h[3] == grid[3][1] + grid[3][2] + grid[3][3]) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h[1] >> h[2] >> h[3] >> w[1] >> w[2] >> w[3];
  for(ll a = 1; a <= 30; a++) {
    for(ll b = 1; b <= 30; b++) {
      for(ll c = 1; c <= 30; c++) {
        for(ll d = 1; d <= 30; d++) {
          ll grid[4][4];
          grid[1][1] = a;
          grid[1][2] = b;
          grid[1][3] = h[1] - grid[1][1] - grid[1][2];
          grid[2][1] = c;
          grid[2][2] = d;
          grid[2][3] = h[2] - grid[2][1] - grid[2][2];
          grid[3][1] = w[1] - grid[1][1] - grid[2][1];
          grid[3][2] = w[2] - grid[1][2] - grid[2][2];
          grid[3][3] = w[3] - grid[1][3] - grid[2][3];
          if(is_valid(grid)) {
            answer++;
          }
        }
      }
    }
  }
  cout << answer << '\n';
  
  return 0;
}
