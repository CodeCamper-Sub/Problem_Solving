#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll cnt = 0;
  for(ll i = 0; i < 500; i++) {
    for(ll j = i + 1; j < 500; j++) {
      for(ll k = i; k <= j; k++) {
        cnt++;
      }
    }
  }

  cout << cnt;
  
  return 0;
}