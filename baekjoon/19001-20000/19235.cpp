#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct Domino {
  vector<vector<ll>> grid;
  ll score, id = 1;

  Domino() {
    grid.assign(6, vector<ll>(4));
  }

  // 꽉 찬 행이 있나 확인하고, 없애기
  bool check() {
    bool result = false;
    for(ll i = 0; i < 6; i++) {
      bool should_removed = true;
      for(ll j = 0; j < 4; j++) {
        if(grid[i][j] == 0) {
          should_removed = false;
          break;
        }
      }
      if(should_removed) {
        for(ll j = 0; j < 4; j++) {
          grid[i][j] = 0;
          result = true;
        }
        score++;
      }
    }
    return result;
  }

  // 중력 적용
  void gravity() {
    for(ll i = 5; i >= 0; i--) {
      for(ll j = 0; j < 4; j++) {
        if(grid[i][j] == 0) continue;
        bool is_horizontal_block = true;
        if(j == 3 || grid[i][j] != grid[i][j + 1]) is_horizontal_block = false;
        if(!is_horizontal_block) {
          ll r = i;
          while(r < 5 && grid[r + 1][j] == 0) r++;
          if(r != i) {
            grid[r][j] = grid[i][j];
            grid[i][j] = 0;
          }
        } else {
          ll r = i;
          while(r < 5 && grid[r + 1][j] == 0 && grid[r + 1][j + 1] == 0) r++;
          if(r != i) {
            grid[r][j] = grid[i][j];
            grid[r][j + 1] = grid[i][j + 1];
            grid[i][j] = 0;
            grid[i][j + 1] = 0;
          }
          j++;
        }
      }
    }
  }

  void remove_bottom() {
    ll cnt = 0;
    for(ll i = 0; i < 2; i++) {
      for(ll j = 0; j < 4; j++) {
        if(grid[i][j] != 0) {
          cnt++;
          break;
        }
      }
    }
    for(ll i = 5; i - cnt >= 0; i--) {
      for(ll j = 0; j < 4; j++) {
        grid[i][j] = grid[i - cnt][j];
      }
    }
    for(ll i = 0; i < 2; i++) {
      for(ll j = 0; j < 4; j++) {
        grid[i][j] = 0;
      }
    }
  }

  // 블럭 넣기
  void insert(ll x, ll d) {
    if(d == 1) {
      // 1개짜리 블럭
      grid[0][x] = id++;
    } else if(d == 2) {
      // 가로블럭
      grid[0][x] = id;
      grid[0][x + 1] = id++;
    } else {
      // 세로블럭
      grid[0][x] = id;
      grid[1][x] = id++;
    }
    gravity();
    while(check()) gravity();
    remove_bottom();
  }

  ll get_remain_block_cnt() {
    ll cnt = 0;
    for(ll i = 0; i < 6; i++) {
      for(ll j = 0; j < 4; j++) {
        if(grid[i][j] != 0) cnt++;
      }
    }
    return cnt;
  }

  void print() {
    for(ll i = 0; i < 6; i++) {
      for(ll j = 0; j < 4; j++) {
        cout << grid[i][j] << ' ';
      }
      cout << '\n';
    }
    cout << "\n\n";
  }
};

Domino a, b;
ll n, x, y, d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  while(n--) {
    cin >> d >> y >> x;
    a.insert(x, d);
    // a.print();
    if(d == 1) {
      b.insert(3 - y, d);
    } else if(d == 2) {
      b.insert(3 - y, 3);
    } else {
      b.insert(2 - y, 2);
    }
    // b.print();
  }

  cout << a.score + b.score << '\n';
  cout << a.get_remain_block_cnt() + b.get_remain_block_cnt() << '\n';
  
  return 0;
}