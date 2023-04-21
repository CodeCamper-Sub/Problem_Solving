#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll r, c, iy, ix;
string commands;
vector<vector<char>> grid;
vector<tuple<ll, ll, bool>> robots;
vector<vector<ll>> robots_cnt;
ll dy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
ll dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

pair<ll, ll> next_robot(ll ry, ll rx) {
  if(ry > iy && rx < ix) {
    // 1사분면
    return {ry - 1, rx + 1};
  } else if(ry > iy && rx == ix) {
    // 위쪽 y축
    return {ry - 1, rx};
  } else if(ry > iy && rx > ix) {
    // 2사분면
    return {ry - 1, rx - 1};
  } else if(ry == iy && rx > ix) {
    // 왼쪽 x축
    return {ry, rx - 1};
  } else if(ry < iy && rx > ix) {
    // 3사분면
    return {ry + 1, rx - 1};
  } else if(ry < iy && rx == ix) {
    // 아래쪽 y축
    return {ry + 1, rx};
  } else if(ry < iy && rx < ix) {
    // 4사분면
    return {ry + 1, rx + 1};
  } else {
    // 오른쪽 x축
    return {ry, rx + 1};
  }
}

void print_grid() {
  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
      if(i == iy && j == ix) {
        cout << 'I';
      } else if(robots_cnt[i][j] == 1) {
        cout << 'R';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r >> c;
  grid.assign(r, vector<char>(c));
  robots_cnt.assign(r, vector<ll>(c, 0));
  for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) {
    cin >> grid[i][j];
    if(grid[i][j] == 'I') {
      iy = i;
      ix = j;
    }
    if(grid[i][j] == 'R') {
      robots.push_back({i, j, false});
      robots_cnt[i][j]++;
    }
  }

  cin >> commands;
  for(ll i = 0; i < commands.size(); i++) {
    ll command = commands[i] - '1';
    ll ny = iy + dy[command], nx = ix + dx[command];
    if(robots_cnt[ny][nx] > 0) {
      cout << "kraj " << i + 1 << '\n';
      return 0;
    }
    iy = ny; ix = nx;
    for(auto &[ry, rx, exploded]: robots) {
      if(exploded) continue;
      auto [ny, nx] = next_robot(ry, rx);
      if(iy == ny && ix == nx) {
        cout << "kraj " << i + 1 << '\n';
        return 0;
      }
      robots_cnt[ry][rx] -= 1;
      robots_cnt[ny][nx] += 1;
      ry = ny, rx = nx;
    }
    for(auto &[ry, rx, exploded]: robots) {
      if(robots_cnt[ry][rx] > 1) {
        exploded = true;
      }
    }
    for(auto [ry, rx, exploded]: robots) {
      if(robots_cnt[ry][rx] > 1) robots_cnt[ry][rx] = 0;
    }
    #ifdef DEBUG
    // print_grid();
    // cout << "\n\n";
    #endif
  }

  print_grid();

  
  return 0;
}