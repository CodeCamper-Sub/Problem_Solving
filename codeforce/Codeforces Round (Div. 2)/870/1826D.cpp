#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> b, bl, br;

void init() {
  cin >> n;
  b.resize(n);
  bl.resize(n);
  br.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> b[i];
  }
}

void solve() {
  bl[0] = b[0];
  br[n - 1] = b[n - 1] - (n - 1);
  for(ll i = 1; i < n; i++) {
    bl[i] = max(bl[i - 1], b[i] + i);
    br[n - 1 - i] = max(br[n - i], b[n - 1 - i] - (n - 1 - i));
  }
  ll answer = -INF;
  for(ll i = 1; i < n - 1; i++) {
    answer = max(answer, b[i] + bl[i - 1] + br[i + 1]);
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