#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

enum Direction { R, L, U, D };

ll n, k, answer;
vector<vector<ll>> grid;
ll dy[4] = {0, 0, -1, 1};
ll dx[4] = {1, -1, 0, 0};

struct Piece {
  deque<pair<ll, Direction>> q;
  ll y, x;
  bool reversed = false; // false면 front가 아래 true면 back이 아래
  Piece(ll y, ll x, ll i, ll d) : y(y), x(x) { q.push_back({i, Direction(d)}); }

  void join(Piece &rhs) {
    while (q.size()) {
      rhs.push_top(*bottom());
      pop_bottom();
    }
  }

  pair<ll, Direction> *bottom() {
    if (!reversed)
      return &q.front();
    else
      return &q.back();
  }

  void push_top(pair<ll, Direction> p) {
    if (!reversed) {
      q.push_back(p);
    } else {
      q.push_front(p);
    }
  }

  void pop_bottom() {
    if (!reversed) {
      q.pop_front();
    } else {
      q.pop_back();
    }
  }
};

vector<Piece *> pieces;

bool is_ok(ll y, ll x) {
  if (y < 0 || y >= n || x < 0 || x >= n || grid[y][x] == 2)
    return false;
  return true;
}

Direction opposite(Direction d) {
  if (d == R)
    return L;
  if (d == L)
    return R;
  if (d == U)
    return D;
  if (d == D)
    return U;
  return L;
}

bool move(ll i) {
  Piece *p = pieces[i];
  Direction d = p->bottom()->second;
  ll ny = p->y + dy[d], nx = p->x + dx[d];
  if (!is_ok(ny, nx)) {
    p->bottom()->second = opposite(d);
    d = p->bottom()->second;
    ny = p->y + dy[d];
    nx = p->x + dx[d];
    if (is_ok(ny, nx)) {
      return move(i);
    }
  } else {
    if (grid[ny][nx] == 1) {
      p->reversed = !(p->reversed);
    }
    ll overlaped = -1;
    for (ll j = 0; j < k; j++) {
      if (pieces[j] == p)
        continue;
      if (pieces[j]->y == ny && pieces[j]->x == nx) {
        p->join(*pieces[j]);
        if(pieces[j]->q.size() >= 4) {
          return false;
        }
        overlaped = j;
        break;
      }
    }
    if (overlaped != -1) {
      for (ll j = 0; j < k; j++) {
        if (pieces[j] != p)
          continue;
        pieces[j] = pieces[overlaped];
      }
    } else {
      p->y = ny;
      p->x = nx;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  grid.assign(n, vector<ll>(n));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  pieces.resize(k);
  for (ll i = 0; i < k; i++) {
    ll y, x, d;
    cin >> y >> x >> d;
    y--;
    x--;
    d--;
    pieces[i] = new Piece(y, x, i, d);
  }

  for (ll t = 1; t <= 1000; t++) {
    for (ll i = 0; i < k; i++) {
      if (pieces[i]->bottom()->first != i)
        continue;
      if(!move(i)) {
        cout << t << '\n';
        return 0;
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}