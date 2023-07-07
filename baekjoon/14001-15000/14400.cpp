#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<ll> x, y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  x.resize(n);
  y.resize(n);
  for(ll i = 0; i < n; i++) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll answer = 0;
  ll cx = x[x.size() / 2];
  ll cy = y[y.size() / 2];

  for(ll i = 0; i < n; i++) {
    answer += abs(x[i] - cx) + (abs(y[i] - cy));
  }

  cout << answer << '\n';
  
  return 0;
}