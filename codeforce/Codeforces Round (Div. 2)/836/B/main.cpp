#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T;
  cin >> T;
  while(T--) {
    cin >> n;
    if(n % 2 != 0) {
      for(ll i = 0; i < n; i++) {
        cout << 1 << ' ';
      }
      cout << '\n';
    } else {
      for(ll i = 0; i < n - 2; i++) {
        cout << 2 << ' ';
      }
      cout << 3 << ' ' << 1 << '\n';
    }
  }

  return 0;
}