#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> b;

void init() {
  cin >> n >> m;
  if(n > m) swap(n, m);
  b.resize(n * m);
  for(ll& b: b) cin >> b;
}

void solve() {
  sort(b.begin(), b.end());
  ll k = b.back() - b[0];
  ll l = max(b.back() - b[1], b[b.size() - 2] - b[0]);
  ll answer = (n * (m - 1)) * k;
  answer += (n - 1) * l;
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