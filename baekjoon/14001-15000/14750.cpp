#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 1010
#define MAXK 10
#define MAXH 100
#define MAXM (MAXK * MAXH)
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  bool operator<=(const Point& rhs) {
    return y != rhs.y ? y < rhs.y : x <= rhs.x;
  }
};

struct Line {
  Point s, e;
};

ll n, k, h, m, capacity[MAXM + MAXH][MAXM + MAXH], flow[MAXM + MAXH][MAXM + MAXH], source, sink, visited[MAXM + MAXH], max_flow;
vector<Point> house, holes, mice;
vector<ll> e[MAXM + MAXH];

ll ccw(Point a, Point b, Point c) {
  ll result = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
  if(result > 0) return 1;
  else if(result < 0) return -1;
  else return 0;
}

bool has_intersect(Line a, Line b) {
  ll ccw_a_b = ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e);
  ll ccw_b_a = ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e);
  if(ccw_a_b == 0 && ccw_b_a == 0) {
    if(a.e <= a.s) swap(a.s, a.e);
    if(b.e <= b.s) swap(b.s, b.e);
    return b.s <= a.e && a.s <= b.e;
  }
  return ccw_a_b <= 0 && ccw_b_a <= 0;
}

bool has_intersect(Line a, Point b) {
  if(a.e <= a.s) swap(a.s, a.e);
  return ccw(a.s, a.e, b) == 0 && a.s <= b && b <= a.e;
}

void network_flow() {
  while(true) {
    fill(visited, visited + MAXM + MAXH, -1);
    queue<ll> q;
    visited[source] = source;
    q.push(source);
    while(!q.empty()) {
      ll now = q.front(); q.pop();
      for(ll next: e[now]) {
        if(visited[next] == -1 && capacity[now][next] - flow[now][next] > 0) {
          visited[next] = now;
          q.push(next);
          if(next == sink) break;
        }
      }
    }
    if(visited[sink] == -1) break;
    ll now = sink;
    ll min_flow = INF;
    while(now != source) {
      ll next = visited[now];
      min_flow = min(min_flow, capacity[next][now] - flow[next][now]);
      now = next;
    }
    now = sink;
    while(now != source) {
      ll next = visited[now];
      flow[next][now] += min_flow;
      flow[now][next] -= min_flow;
      now = next;
    }
    max_flow += min_flow;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> h >> m;
  for(ll i = 0; i < n; i++) {
    Point p;
    cin >> p.x >> p.y;
    house.push_back(p);
  }

  for(ll i = 0; i < h; i++) {
    Point p;
    cin >> p.x >> p.y;
    holes.push_back(p);
  }

  for(ll i = 0; i < m; i++) {
    Point p;
    cin >> p.x >> p.y;
    mice.push_back(p);
  }

  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < m; j++) {
      bool connectable = true;
      for(ll k = 0; k < n; k++) {
        Line wall = {house[k], house[(k + 1) % n]};
        if(has_intersect(wall, holes[i])) continue;
        Line sight = {holes[i], mice[j]};
        if(has_intersect(wall, sight)) {
          connectable = false;
          break;
        }
      }
      if(connectable) {
        e[j].push_back(m + i);
        e[m + i].push_back(j);
        capacity[j][m + i] += 1;
      }
    }
  }

  source = m + h;
  sink = m + h + 1;

  for(ll i = 0; i < m; i++) {
    e[source].push_back(i);
    e[i].push_back(source);
    capacity[source][i] += 1;
  }

  for(ll i = 0; i < h; i++) {
    e[m + i].push_back(sink);
    e[sink].push_back(m + i);
    capacity[m + i][sink] += k;
  }

  network_flow();

  if(max_flow == m) {
    cout << "Possible\n";
  } else {
    cout << "Impossible\n";
  }
  
  return 0;
}