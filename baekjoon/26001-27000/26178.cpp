#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll a, b;
string s;
vector<ll> e;

struct Rational {
  ll dividend, divider;

  Rational(ll dividend, ll divider): dividend(dividend), divider(divider) { }

  bool operator<=(Rational rhs) {
    ll g = gcd(divider, rhs.divider);
    return dividend * rhs.divider / g <= rhs.dividend * divider / g;
  }
  
  bool operator<(Rational rhs) {
    ll g = gcd(divider, rhs.divider);
    return dividend * rhs.divider / g < rhs.dividend * divider / g;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '/') {
      a = stoi(s.substr(0, i));
      b = stoi(s.substr(i + 1));
      break;
    }
  }
  ll k = 0;
  while(++k) {
    Rational mini(b * k - 1, b * k);
    Rational maxi(b * k - 1, 2);
    if(Rational(a, b) < mini) {
      cout << "impossible\n";
      return 0;
    }
    if(Rational(a, b) <= maxi) {
      ll n = b * k;
      e.resize(n + 1);

      e[1] = -1;
      for(ll i = 2; i <= n; i++) e[i] = i - 1;
      ll delta = (n - 1) * n / 2 - a * k;
      for(ll i = n; i >= 2; i--) {
        if(delta >= i - 2) {
          delta -= i - 2;
          e[i] = 1;
        } else {
          e[i] = i - delta - 1;
          delta = 0;
          break;
        }
      }
      cout << n << ' ' << n - 1 << '\n';
      for(ll i = 2; i <= n; i++) {
        cout << e[i] << ' ' << i << '\n';
      }
      
      return 0;
    }
  }
  
  return 0;
}