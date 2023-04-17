#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll r, c;
vector<vector<ll>> grid, ldp, rdp; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r >> c;
  grid.assign(r, vector<ll>(c));
  ldp.assign(r, vector<ll>(c));
  rdp.assign(r, vector<ll>(c));
  for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) {
    char k;
    cin >> k;
    grid[i][j] = k - '0';
  }

  for(ll i = 0; i < r + c - 1; i++) {
    for(ll j = 0; j <= i; j++) {
      ll y = r - 1 - j;
      ll x = c - 1 - i + j;
      if(y >= r || y < 0 || x >= c || x < 0) continue;
      if(grid[y][x] == 0) {
        ldp[y][x] = 0;
      } else if(y == r - 1 || x == 0 || grid[y + 1][x - 1] == 0) {
        ldp[y][x] = 1;
      } else {
        ldp[y][x] = ldp[y + 1][x - 1] + 1;
      }
    }
  }

  for(ll i = 0; i < r + c - 1; i++) {
    for(ll j = 0; j <= i; j++) {
      ll y = r - 1 - j;
      ll x = i - j;
      if(y >= r || y < 0 || x >= c || x < 0) continue;
      if(grid[y][x] == 0) {
        rdp[y][x] = 0;
      } else if(y == r - 1 || x == c - 1 || grid[y + 1][x + 1] == 0) {
        rdp[y][x] = 1;
      } else {
        rdp[y][x] = rdp[y + 1][x + 1] + 1;
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
      // 현재 위치에서 만들 수 있는 가장 긴 변의 길이
      ll len = (r - i + 1) / 2;
      len = min(len, min(j + 1, c - j));
      len = min(len, ldp[i][j]);
      len = min(len, rdp[i][j]);
      
      if(len <= answer) continue;

      do {
        ll ly = i + len - 1, ry = i + len - 1;
        ll lx = j - len + 1, rx = j + len - 1;
        if(rdp[ly][lx] >= len && ldp[ry][rx] >= len) {
          answer = max(answer, len);
          break;
        }
      } while(--len > answer);
    }
  }

  cout << answer << '\n';
  
  return 0;
}