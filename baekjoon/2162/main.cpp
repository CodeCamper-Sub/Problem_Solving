#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  bool operator<=(Point operand) {
    if(x != operand.x) {
      return x < operand.x;
    } else {
      return y <= operand.y;
    }
  }
};

struct Segment {
  Point p1, p2;
};

ll N, group_cnt, maximum;

vector<Segment> v;  // x1, y1, x2, y2;

bool connected[5050][5050];
bool visited[5050];

ll ccw(Point a, Point b, Point c) {
  ll result = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
  if(result > 0) {
    return 1;
  } else if ( result == 0) {
    return 0;
  } else {
    return -1;
  }
}

bool is_connected(Segment a, Segment b) {
  Point p[4] = {a.p1, b.p1, a.p2, b.p2};
  ll ccw_result[4];
  ll ccw_zero_cnt = 0;
  bool result = true;
  for(ll i = 0; i < 4; i++) {
    ccw_result[i] = ccw(p[i], p[(i+1)%4], p[(i+2)%4]);
    if(ccw_result[i] == 0) {
      ccw_zero_cnt += 1;
    }
  }
  if(ccw_zero_cnt < 4) {
    for(ll i = 0; i < 4; i++) {
      if(ccw_result[i] * ccw_result[(i+1)%4] < 0) {
        result = false;
        break;
      }
    }
  } else {
    if(p[2] <= p[0]) swap(p[0], p[2]);
    if(p[3] <= p[1]) swap(p[1], p[3]);
    if(p[1] <= p[2] && p[0] <= p[3]) {
      result = true;
    } else {
      result = false;
    }
  }
  return result;
}

ll dfs(ll node) {
  ll cnt = 1;
  for(ll i = 0; i < v.size(); i++) {
    if(connected[node][i] && !visited[i]) {
      visited[i] = true;
      cnt += dfs(i);
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for(ll i = 0; i < N; i++) {
    Segment s;
    cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
    v.push_back(s);
  }

  for(ll i = 0; i < v.size(); i++) {
    for(ll j = 0; j < v.size(); j++) {
      if(i == j) continue;
      connected[i][j] = is_connected(v[i], v[j]);
    }
  }

  for(ll i = 0; i < v.size(); i++) {
    if(!visited[i]) {
      group_cnt++;
      visited[i] = true;
      maximum = max(maximum, dfs(i));
    }
  }

  cout << group_cnt << '\n';
  cout << maximum << '\n';
  
  return 0;
}