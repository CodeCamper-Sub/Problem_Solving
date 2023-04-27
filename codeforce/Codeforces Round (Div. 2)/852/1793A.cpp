#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll a, b, n, m;

void init() {
  cin >> a >> b >> n >> m;
}

void solve() {
  if(a * m > b * (m + 1)) {
    cout << b * n << '\n';
    return;
  }
  
  ll answer = 0;
  answer += n / (m + 1) * a * m;
  n %= (m + 1);

  answer += n * min(a, b);

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