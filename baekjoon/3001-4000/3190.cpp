#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

enum Direction {
  L,
  U,
  R,
  D
};

ll n, k, l, hy, hx, ty, tx, t, len;
Direction hd, td;
vector<vector<ll>> apple, visited;
queue<pair<ll, ll>> command, tcommand;

tuple<bool, ll, ll> go(ll y, ll x, Direction d) {
  ll ny, nx;
  if(d == L) {
    ny = y;
    nx = x - 1;
  } else if(d == R) {
    ny = y;
    nx = x + 1;
  } else if(d == U) {
    ny = y - 1;
    nx = x;
  } else {
    ny = y + 1;
    nx = x;
  }
  if(ny <= 0 || ny > n || nx <= 0 || nx > n || visited[ny][nx]) return {false, ny, nx};
  return {true, ny, nx};
}

Direction rotate(Direction d, char c) {
  if(c == 'D') {
    return Direction((d + 1) % 4);
  } else {
    return Direction((d - 1 + 4) % 4);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  apple.resize(n + 1, vector<ll>(n + 1, false));
  visited.resize(n + 1, vector<ll>(n + 1, false));
  cin >> k;
  for(ll i = 0; i < k; i++) {
    ll y, x;
    cin >> y >> x;
    apple[y][x] = true;
  }
  cin >> l;
  for(ll i = 0; i < l; i++) {
    ll x;
    char c;
    cin >> x >> c;
    command.push({x, c});
  }
  
  hy = 1;
  hx = 1;
  ty = 1;
  tx = 1;
  hd = R;
  td = R;
  len = 0;
  while(true) {
    t++;
    auto [can_go, nhy, nhx] = go(hy, hx, hd);
    if(!can_go) break;
    visited[nhy][nhx] = true;
    hy = nhy;
    hx = nhx;
    if(!apple[nhy][nhx]) {
      auto [_, nty, ntx] = go(ty, tx, td);
      visited[ty][tx] = false;
      ty = nty;
      tx = ntx;
    } else {
      len += 1;
      apple[hy][hx] = false;
    }
    if(command.size() && command.front().first == t) {
      hd = rotate(hd, command.front().second);
      tcommand.push(command.front());
      command.pop();
    }
    if(tcommand.size() && tcommand.front().first + len == t) {
      td = rotate(td, tcommand.front().second);
      tcommand.pop();
    }
  }

  cout << t << '\n';
  
  return 0;
}