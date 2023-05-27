#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> a;
  cout << a << ' ';
  ll a2;
  for(ll i = 0; i < n - 1; i++) {
    cin >> a2;
    if(a < a2) {
      for(ll j = a + 1; j < a2; j++) {
        cout << j << ' ';
      }
    } else {
      for(ll j = a - 1; j > a2; j--) {
        cout << j << ' ';
      }
    }
    cout << a2 << ' ';
    a = a2;
  }

  
  return 0;
}