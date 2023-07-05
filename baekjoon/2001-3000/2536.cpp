#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll m, n, k, sy, sx, ey, ex, source, sink;
vector<vector<int>> e;
using Bus = tuple<ll, ll, ll, ll>;
using Point = pair<ll, ll>;
vector<Bus> buses;

ll ccw(Point a, Point b, Point c) {
  ll result = a.first * b.second + b.first * c.second + c.first * a.second - b.first * a.second - c.first * b.second - a.first * c.second;
  if(result > 0) result = 1;
  else if(result == 0) result = 0;
  else if(result < 0) result = -1;
  return result;
}

bool intersects(Bus a, Bus b) {
  auto [a_x1, a_y1, a_x2, a_y2] = a;
  auto [b_x1, b_y1, b_x2, b_y2] = b;
  Point a1 = {a_x1, a_y1};
  Point a2 = {a_x2, a_y2};
  Point b1 = {b_x1, b_y1};
  Point b2 = {b_x2, b_y2};
  ll ccw_a_b = ccw(a1, a2, b1) * ccw(a1, a2, b2);
  ll ccw_b_a = ccw(b1, b2, a1) * ccw(b1, b2, a2);
  if(ccw_a_b == 0 && ccw_b_a == 0) {
    if(a1 > a2) swap(a1, a2);
    if(b1 > b2) swap(b1, b2);
    return a1 <= b2 && b1 <= a2;
  }
  return ccw_a_b <= 0 && ccw_b_a <= 0;
}

ll dijikstra() {
  vector<ll> visited(k + 2, INF);
  visited[source] = 0;
  queue<ll> q;
  q.push({source});
  while(q.size()) {
    ll now = q.front();
    q.pop();
    for(ll next: e[now]) {
      if(visited[next] > visited[now] + 1) {
        visited[next] = visited[now] + 1;
        q.push({next});
      }
    }
  }
  return visited[sink] - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n >> k;
  buses.resize(k + 2);
  e.resize(k + 2);
  for(ll i = 0; i < k; i++) {
    ll b, x1, y1, x2, y2;
    cin >> b >> x1 >> y1 >> x2 >> y2;
    buses[b] = {x1, y1, x2, y2};
  }

  cin >> sx >> sy >> ex >> ey;
  source = 0;
  sink = k + 1;
  buses[source] = {sx, sy, sx, sy};
  buses[sink] = {ex, ey, ex, ey};

  for(ll i = 0; i <= k + 1; i++) {
    for(ll j = i + 1; j <= k + 1; j++) {
      if(intersects(buses[i], buses[j])) {
        e[i].push_back(j);
        e[j].push_back(i);
      }
    }
  }

  cout << dijikstra() << '\n';
  
  return 0;
}