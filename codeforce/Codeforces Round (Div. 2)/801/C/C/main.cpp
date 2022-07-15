//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, m;
ll grid[1010][1010];
ll minimum[1010][1010];
ll maximum[1010][1010];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    testcase();
  }
  return 0;
}

void testcase() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if(i == 1 && j == 1) {
        minimum[i][j] = grid[i][j];
        maximum[i][j] = grid[i][j];
      } else if (i == 1) {
        minimum[i][j] = grid[i][j] + minimum[i][j-1];
        maximum[i][j] = grid[i][j] + maximum[i][j-1];
      } else if (j == 1) {
        minimum[i][j] = grid[i][j] + minimum[i-1][j];
        maximum[i][j] = grid[i][j] + maximum[i-1][j];
      } else {
        minimum[i][j] = grid[i][j] + min(minimum[i-1][j], minimum[i][j-1]);
        maximum[i][j] = grid[i][j] + max(maximum[i-1][j], maximum[i][j-1]);
      }
    }
  }
  if((n + m - 1) % 2 == 1) {
    cout << "NO\n";
    return;
  }
  if(minimum[n][m] <= 0 && maximum[n][m] >= 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

