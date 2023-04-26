#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, sum;
vector<ll> p;

void init() {
  cin >> n;
  p.resize(n * 2);
  for(ll& p: p) cin >> p;
}

void solve() {
  if(n == 1) {
    cout << abs(p[0] - p[1]) << '\n';
    return;
  }
  ll answer = 0;
  sum = 0;
  for(ll i = 0; i < 2 * n; i++) {
    sum += abs(p[i]);
  }
  if(n % 2) {
    cout << sum << '\n';
    return;
  }
  answer = sum;
  sum = 0;

  ll maxi = -INF;
  for(ll i = 0; i < 2 * n; i++) {
    sum += abs(-1 - p[i]);
    maxi = max(maxi, abs(-1 - p[i]) - abs(n - p[i]));
  }
  sum -= maxi;
  answer = min(answer, sum);


  if(n == 2) {
    sum = 0;
    for(ll i = 0; i < 2 * n; i++) {
      sum += abs(2 - p[i]);
    }
    answer = min(answer, sum);
  }
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