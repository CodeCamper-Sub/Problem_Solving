#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll prefix_sum[330][330][330];
ll grid[330][330];
ll H, W, N, h, w;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> H >> W >> N >> h >> w;
  for(ll i = 0; i < H; i++) {
    for(ll j = 0; j < W; j++) {
      cin >> grid[i][j];
      for(ll n = 1; n <= N; n++) {
        if(grid[i][j] == n) {
          prefix_sum[n][i][j] = 1;
        }
      }
    }
  }
  for(ll n = 1; n <= N; n++) {
    for(ll i = 0; i < H; i++) {
      for(ll j = 1; j < W; j++) {
        prefix_sum[n][i][j] += prefix_sum[n][i][j-1];
      }
    }

    for(ll j = 0; j < W; j++) {
      for(ll i = 1; i < H; i++) {
        prefix_sum[n][i][j] += prefix_sum[n][i-1][j];
      }
    }
  }

  for(ll i = 0; i <= H - h; i++) {
    for(ll j = 0; j <= W - w; j++) {
      ll answer = 0;
      for(ll n = 1; n <= N; n++) {
        ll total = prefix_sum[n][H-1][W-1];
        ll blacked = prefix_sum[n][i+h-1][j+w-1];
        if(i > 0) {
          blacked -= prefix_sum[n][i-1][j+w-1];
        }
        if(j > 0) {
          blacked -= prefix_sum[n][i+h-1][j-1];
        }
        if(i > 0 && j > 0) {
          blacked += prefix_sum[n][i-1][j-1];
        }
        if(total-blacked > 0) answer++;
      }
      cout << answer << ' ' ;
    }
    cout << '\n';
  }



  return 0;
}