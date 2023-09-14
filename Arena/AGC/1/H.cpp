#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

vector<ll> row, col;
ll n, m, q, c, r, v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> q;
  row.resize(n + 1);
  col.resize(m + 1);

  for(ll i = 0; i < q; i++) {
    cin >> c >> r >> v;
    if(c == 1) {
      row[r] += v;
    } else {
      col[r] += v;
    }
  }

  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= m; j++) {
      cout << row[i] + col[j] << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}