#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, maximum, ay, ax;
ll grid[20][20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  maximum = -INF;

  for(ll i = 1; i <= 9; i++) {
    for(ll j = 1; j <= 9; j++) {
      cin >> grid[i][j];
      if(maximum <= grid[i][j]) {
        maximum = grid[i][j];
        ay = i;
        ax = j;
      }
    }
  }
  cout << maximum << '\n';
  cout << ay << ' ' << ax << '\n';
  return 0;
}