#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;
typedef long double ld;
ld a, d, k;
ld ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ld ss = 0;
  ld tt = 1;
  cin >> a >> d >> k;
  while(d < 100){
    ss += a;
    ld tmp = d;
    tmp = tmp/100;
    ans += tt*tmp*ss;
    tt = tt * (1-tmp);
    d += d*k/100;
  }
  ss+=a;
  ans += ss * tt;
  cout << fixed;
  cout.precision(10);
  cout << ans;
  
  return 0;
}