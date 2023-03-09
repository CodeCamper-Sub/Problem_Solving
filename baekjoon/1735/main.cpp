#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a, b, c, d;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b >> c >> d;

  ll _a = a * d;
  ll _b = b * d;
  ll _c = c * b;
  ll _d = d * b;

  ll g = gcd(_a + _c, b * d);

  cout << (_a + _c) / g << ' ' << b * d / g << '\n';
  
  return 0;
}