#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<pair<ll, ll>> points;

void init() {
  points.resize(3);
  cin >> points[0].first >> points[0].second;
  cin >> points[1].first >> points[1].second;
  cin >> points[2].first >> points[2].second;
}

void solve() {
  set<ll> s1, s2;
  for(ll i = 0; i < 3; i++) {
    s1.insert(points[i].first);
    s2.insert(points[i].second);
  }

  if(s1.size() == 2 && s2.size() == 2) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}