#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

char grid[10][10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 8; i >= 1; i--) {
    for(ll j = 0; j < 8; j++) {
        cin >> grid[i][j];
        if(grid[i][j] == '*') {
            cout << char('a' + j) << i << '\n';
        }
    }
  }
  
  return 0;
}