#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, _r;
vector<tuple<ll, ll, ll>> v;

double dist(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
  auto [ax, ay, az] = a;
  auto [bx, by, bz] = b;
  return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by) + (az - bz) * (az - bz));
}

double intersection(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
  double r = _r;
  double d = dist(a, b);
  return 2.0 * M_PI * (r - d / 2.0) * (r - d / 2.0) * (2.0 * r + d / 2.0) / 3.0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> _r;
  v.resize(n);
  for(auto& [x, y, z]: v) {
    cin >> x >> y >> z;
  }

  double r = _r;
  double answer = 4.0 * M_PI * r * r * r / 3.0;
  answer *= n;

  double intersections = 0;
  for(ll i = 0; i < n; i++) {
    intersections += intersection(v[i], v[(i + 1) % n]);
  }

  answer -= intersections;

  cout << fixed;
  cout.precision(8);
  cout << answer << '\n';
  
  return 0;
}