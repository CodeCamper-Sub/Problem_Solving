#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> d;
  ll pre_t = -INF, t;
  for(ll i = 0; i < n; i++) {
    cin >> t;
    if(t - pre_t <= d) {
      cout << t << '\n';
      return 0;
    }
    pre_t = t;
  }

  cout << -1 << '\n';
  
  return 0;
}