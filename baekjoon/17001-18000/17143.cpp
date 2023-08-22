#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll r, c, m;
vector<vector<tuple<ll, ll, ll>>> sharks;
queue<tuple<ll, ll, ll, ll, ll>> q;

ll dy[4] = {-1, 1, 0, 0};
ll dx[4] = {0, 0, 1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r >> c >> m;
  sharks.assign(r, vector<tuple<ll, ll, ll>>(c, {-1, -1, -1}));

  for(ll i = 0; i < m; i++) {
    ll y, x, s, d, z;
    cin >> y >> x >> s >> d >> z;
    y--; x--; d--;
    if(d == 0 || d == 1) {
      s %= (r - 1) * 2;
    } else {
      s %= (c - 1) * 2;
    }
    sharks[y][x] = {s, d, z};
  }

  ll answer = 0;
  for(ll now = 0; now < c; now++) {
    for(ll j = 0; j < r; j++) {
      auto& [s, d, z] = sharks[j][now];
      if(s != -1) {
        answer += z;
        s = -1; d = -1; z = -1;
        break;
      }
    }

    for(ll i = 0; i < r; i++) {
      for(ll j = 0; j < c; j++) {
        auto [s, d, z] = sharks[i][j];
        if(s != -1) {
          q.push({i, j, s, d, z});
        }
      }
    }

    sharks.assign(r, vector<tuple<ll, ll, ll>>(c, {-1, -1, -1}));
    while(q.size()) {
      auto [y, x, s, d, z] = q.front();
      q.pop();

      ll delta = s;
      while(delta) {
        if(d == 0) {
          if(y >= delta) {
            y -= delta;
            delta = 0;
          } else {
            delta -= y;
            y = 0;
            d = 1;
          }
        } else if(d == 1) {
          if(y + delta < r) {
            y += delta;
            delta = 0;
          } else {
            delta -= r - y - 1;
            y = r - 1;
            d = 0;
          }
        } else if(d == 2) {
          if(x + delta < c) {
            x += delta;
            delta = 0;
          } else {
            delta -= c - x - 1;
            x = c - 1;
            d = 3;
          }   
        } else { // d == 3 
          if(x >= delta) {
            x -= delta;
            delta = 0;
          } else {
            delta -= x;
            x = 0;
            d = 2;
          }
        }
      }

      if(get<2>(sharks[y][x]) < z) {
        sharks[y][x] = {s, d, z};
      }
    }
  }

  cout << answer << '\n';

  return 0;
}