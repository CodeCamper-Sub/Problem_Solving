#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll d, p, q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> d >> p >> q;
  if(p > q) swap(p, q);

  ll n = d / lcm(p, q);
  if(n > 0) {
    n--;
    d = d - lcm(p, q) * n;
  }

  ll answer = INF;
  for(ll i = 0; (i - 1) * q <= d; i++) {
    if(i * q >= d) {
      answer = min(answer, i * q);
    } else {
      ll remain = d - i * q;
      answer = min(answer, i * q + (remain / p + (remain % p ? 1 : 0)) * p);
    }
  }

  cout << answer + n * lcm(p, q) << '\n';
  
  return 0;
}