#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

using Point = pair<ll, ll>;
ll n;
vector<Point> p;
double answer;

void init() {
  cin >> n;
  p.resize(n);
  for(Point& p: p) cin >> p.first >> p.second;
}

void solve() {
  vector<ll> select;
  for(ll i = 0; i < n / 2; i++) {
    select.push_back(0);
  }
  for(ll i = 0; i < n / 2; i++) {
    select.push_back(1);
  }
  answer = INF;
  do {
    ll y = 0, x = 0;
    for(ll i = 0; i < select.size(); i++) {
      if(select[i] == 0) {
        y += p[i].second;
        x += p[i].first;
      } else {
        y -= p[i].second;
        x -= p[i].first;
      }
    }
    answer = min(answer, sqrt(y * y + x * x));
  } while(next_permutation(select.begin(), select.end()));
  cout << fixed;
  cout.precision(15);
  cout << answer << '\n';
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