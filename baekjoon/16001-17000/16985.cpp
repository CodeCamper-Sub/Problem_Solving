#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

vector<vector<vector<ll>>> grid[5];  // [i][j][k][l]
vector<vector<vector<ll>>> dist;

ll dz[6] = {0, 0, 0, 0, 1, -1};
ll dy[6] = {0, 0, 1, -1, 0, 0};
ll dx[6] = {1, -1, 0, 0, 0, 0};

void fill_inf(vector<vector<vector<ll>>>& v) {
  for_each(v.begin(), v.end(), [](auto& layer) {
    for_each(layer.begin(), layer.end(), [](auto& row) {
      fill(row.begin(), row.end(), INF);
    });
  });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  dist.resize(5);
  for_each(dist.begin(), dist.end(), [](auto& layer) {
    layer.assign(5, vector<ll>(5, INF));
  });

  for(ll i = 0; i < 5; i++) {
    grid[i].resize(4);
    for(ll j = 0; j < 4; j++) {
      grid[i][j].assign(5, vector<ll>(5));
    }
    
    for(ll j = 0; j < 5; j++) {
      for(ll k = 0; k < 5; k++){
        cin >> grid[i][0][j][k];
      }
    }

    for(ll j = 0; j < 5; j++) {
      for(ll k = 0; k < 5; k++) {
        // grid[i][1] => 시계방향 90도 회전
        grid[i][1][j][k] = grid[i][0][4 - k][j];
        // grid[i][2] => 시계방향 180도 회전
        grid[i][2][j][k] = grid[i][0][4 - j][4 - k];
        // grid[i][3] => 시계방향 270도 회전
        grid[i][3][j][k] = grid[i][0][k][4 - j];
      }
    }
  }
  ll answer = INF;
  for(ll ii = 0; ii < 4; ii++) {
    for(ll jj = 0; jj < 4; jj++) {
      for(ll kk = 0; kk < 4; kk++) {
        for(ll mm = 0; mm < 4; mm++) {
          for(ll nn = 0; nn < 4; nn++) {
            vector<vector<vector<ll>>> maze;
            maze.push_back(grid[0][ii]);
            maze.push_back(grid[1][jj]);
            maze.push_back(grid[2][kk]);
            maze.push_back(grid[3][mm]);
            maze.push_back(grid[4][nn]);
            sort(maze.begin(), maze.end());
            do {
              // {0, 0, 0} 출발, {4, 4, 4} 도착
              if(maze[0][0][0] == 0 || maze[4][4][4] == 0) continue;
              fill_inf(dist);
              dist[0][0][0] = 0;
              queue<tuple<ll, ll, ll>> q;
              q.push({0, 0, 0});
              while(q.size()) {
                auto [z, y, x] = q.front();
                q.pop();
                for(ll k = 0; k < 6; k++) {
                  ll nz = z + dz[k], ny = y + dy[k], nx = x + dx[k];
                  if(nz < 0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || maze[nz][ny][nx] == 0) continue;
                  if(dist[nz][ny][nx] > dist[z][y][x] + 1) {
                    dist[nz][ny][nx] = dist[z][y][x] + 1;
                    q.push({nz, ny, nx});
                  }
                }
                if(dist[4][4][4] != INF) break;
              }
              answer = min(answer, dist[4][4][4]);
            } while(next_permutation(maze.begin(), maze.end()));
          }
        }
      }
    }
  }

  if(answer != INF) {
    cout << answer << '\n';
  } else {
    cout << -1 << '\n';
  }
  
  return 0;
}