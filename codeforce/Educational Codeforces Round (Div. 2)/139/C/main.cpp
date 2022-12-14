#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n;
char grid[3][200200];

ll status; // 0: 위쪽, 1: 아래쪽, 2: 양쪽, -1: 불가능

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    cin >> n;
    string s;
    cin >> s;
    for(ll i = 0; i < n; i++) {
      grid[0][i] = s[i];
    }
    cin >> s;
    for(ll i = 0; i < n; i++) {
      grid[1][i] = s[i];
    }
    if(grid[0][0] == 'B' && grid[1][0] == 'B') {
      status = 2;
    } else if(grid[0][0] == 'B') {
      status = 0;
    } else {
      status = 1;
    }
    for(ll i = 1; i < n; i++) {
      if(grid[0][i] == 'B' && grid[1][i] == 'B') {
        if (status == 0) status = 1;
        else if (status == 1) status = 0;
        else if (status == 2) status = 2;
      } else if (grid[0][i] == 'B') {
        if (status == 0) status = 0;
        else if (status == 1) status = -1;
        else if (status == 2) status = 0;
      } else {
        if (status == 0) status = -1;
        else if (status == 1) status = 1;
        else if (status == 2) status = 1;
      }

      if(status == -1) break;
    }
    if(status == -1) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }

  return 0;
}