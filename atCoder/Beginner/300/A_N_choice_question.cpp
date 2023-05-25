#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> a >> b;
  for(ll i = 1; i <= n; i++) {
    ll c;
    cin >> c;
    if(c == a + b) {
      cout << i << '\n';
    }
  }
  
  return 0;
}