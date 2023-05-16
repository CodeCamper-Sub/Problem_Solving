#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll s, N, K, r1, r2, c1, c2;

bool should_color(ll w, ll y, ll x) {
  ll nw = w / N;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      ll y_lower = nw * i, y_upper = nw * (i + 1);
      ll x_lower = nw * j, x_upper = nw * (j + 1);
      if (y_lower <= y && y < y_upper && x_lower <= x && x < x_upper) {
        ll lower = (N - K) / 2, upper = N - (N - K) / 2;
        if(lower <= i && i < upper && lower <= j && j < upper) return true;
        else {
          ll ny = y - nw * i;
          ll nx = x - nw * j;
          return should_color(nw, ny, nx);
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;
  ll w = pow(N, s);
  for(ll i = 0; i <= r2 - r1; i++) {
    for(ll j = 0; j <= c2 - c1; j++) {
      cout << should_color(w, r1 + i, c1 + j);
    }
    cout << '\n';
  }

  return 0;
}