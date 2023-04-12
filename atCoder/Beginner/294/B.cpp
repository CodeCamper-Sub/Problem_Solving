#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll grid[110][110];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll h, w;
  cin >> h >> w;
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 0) {
        cout << '.';
      } else {
        cout << char('A' + grid[i][j] - 1);
      }
    }
    cout << '\n';
  }
  
  return 0;
}