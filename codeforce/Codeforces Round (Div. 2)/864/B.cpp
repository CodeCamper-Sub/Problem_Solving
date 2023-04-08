#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, k, cost;
vector<vector<ll>> a;

void init() {
  cin >> n >> k;
  cost = 0;
  a.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> a[i][j];
}

void solve() {
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      if(a[i][j] != a[n - 1 - i][n - 1 - j]) cost++;
    }
  }
  k -= cost / 2;
  if(k >= 0 && (k % 2 == 0 || n % 2 == 1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}