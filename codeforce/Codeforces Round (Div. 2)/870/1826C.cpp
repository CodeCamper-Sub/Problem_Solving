#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;

void init() {
  cin >> n >> m;
}

void solve() {
  if(m == 1 || n == 1) {
    cout << "YES\n";
    return;
  }
  if(n % 2 == 0 || n <= m) {
    cout << "NO\n";
    return;
  }
  // n이 홀수고 m은 2보다 큰 자연수
  for(ll i = 2; i * i <= n; i++) {
    if(n % i) continue;
    if(i <= m || (n / i) <= m) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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