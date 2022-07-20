//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, m, grid[2000][2000], x1, y1, x2, y2;
ll sum[2000][2000], answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      cin >> grid[i][j];
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
    }
  }
  for(ll i = 1; i <= m; i++) {
    answer = 0;
    cin >> y1 >> x1 >> y2 >> x2;
    if(y1 > y2) {
      swap(y1, y2);
    }
    if(x1 > x2) {
      swap(x1, x2);
    }
    answer = sum[y2][x2] - sum[y2][x1-1] - sum[y1-1][x2] + sum[y1-1][x1-1];
    cout << answer << '\n';
  }
  
  
  return 0;
}

