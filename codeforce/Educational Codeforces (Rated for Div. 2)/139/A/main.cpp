#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, cnt;
ll memo[1001000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  for(ll i = 0; i <= 999999; i++) memo[i] = 0;
  ll k = 1;
  while(k <= 999999) {
    for(ll i = 1; i <= 10; i++) {
      memo[k * i] = 1;
    }
    k *= 10;
  }
  for(ll i = 1; i <= 999999; i++) {
    memo[i] = memo[i-1] + memo[i];
  }
  while(tt--) {
    cin >> n;
    cout << memo[n] << '\n';
  }

  return 0;
}