#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;
ll n, now;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s >> n;
  ll k = 1;
  for(ll i = s.size() - 1; i >= 0; i--) {
    if(s[i] == '1') {
      now += k;
    }
    k *= 2;
  }

  if(now > n) {
    cout << -1 << '\n';
    return 0;
  }

  for(ll i = 0; i < s.size(); i++) {
    if(s[i] != '?') continue;
    ll k = (1ll << (s.size() - i - 1));
    if(now + k <= n) {
      now += k;
    }
  }

  cout << now << '\n';
  
  return 0;
}