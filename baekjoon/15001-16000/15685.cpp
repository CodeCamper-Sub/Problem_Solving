#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

enum Direction {
  R,
  U,
  L,
  D
};

Direction rotate(Direction d) {
  switch(d) {
    case L:
    return D;
    case R:
    return U;
    case U:
    return L;
    case D:
    return R;
  }
}

pair<ll, ll> go(ll y, ll x, Direction d) {
  switch(d) {
    case L:
    return {y, x - 1};
    case R:
    return {y, x + 1};
    case U:
    return {y - 1, x};
    case D:
    return {y + 1, x};
  }
}

ll n, x, y, d, g;
vector<vector<ll>> visited;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  visited.resize(101, vector<ll>(101, false));
  
  for(ll i = 0; i < n; i++) {
    cin >> x >> y >> d >> g;
    vector<Direction> v;
    v.push_back(Direction(d));
    for(ll j = 1; j <= g; j++) {
      ll t = v.size();
      while(t--) {
        v.push_back(rotate(v[t]));
      }
    }

    visited[y][x] = true;
    for(ll j = 0; j < v.size(); j++) {
      tie(y, x) = go(y, x, v[j]);
      if(y >= 0 && y <= 100 && x >= 0 && x <= 100) {
        visited[y][x] = true;
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < 100; i++) {
    for(ll j = 0; j < 100; j++) {
      if(visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
        answer++;
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}