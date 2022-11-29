#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, x;
ll arr[200200];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T;
  cin >> T;
  while(T--) {
    cin >> n >> x;
    if(n % x != 0) {
      cout << -1 << '\n';
      continue;
    }
    for(ll i = 1; i <= n; i++) {
      arr[i] = i;
    }
    if(n == x) {
      arr[1] = x;
      arr[n] = 1;
      for(ll i = 1; i <= n; i++) {
      cout << arr[i] << ' ';
    }
      cout << '\n';
      continue;
    }
    arr[1] = x;
    arr[n] = 1;
    arr[x] = n;
    ll now = x;
    while(now < n) {
      ll k = 2;
      while(now * k < n) {
        if(n % (now * k) == 0) {
          ll tmp = arr[now];
          arr[now] = arr[now*k];
          arr[now*k] = tmp;
          now = now * k;
          break;
        } else {
          k++;
        }
      }
      if(now * k >= n) {
        break;
      }
    }
    for(ll i = 1; i <= n; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}