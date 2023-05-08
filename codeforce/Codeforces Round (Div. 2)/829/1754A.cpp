#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, a;
string s;

void init() {
  cin >> n >> s;
}

void solve() {
  a = 0;
  for(ll i = n - 1; i >= 0; i--) {
    if(s[i] == 'Q') {
      a--;
    } else {
      a++;
    }
    if(a < 0) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}