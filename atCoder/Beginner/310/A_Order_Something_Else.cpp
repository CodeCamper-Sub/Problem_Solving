#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, q, p;
vector<ll> d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> p >> q;
  d.resize(n);
  ll mini = INF;
  for(ll& d: d) {
    cin >> d;
    mini = min(mini, d);
  }

  cout << min(p, q + mini) << '\n';
  
  return 0;
}