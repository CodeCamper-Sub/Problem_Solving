#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;

void init() {
  cin >> s;
}

bool recursion(ll now) {
  if(now == 0) return true;
  for(ll i = 1; i <= now; i++) {
    if(s[now - i] == s[now + i]) return false;
  }
  return recursion(now / 2);
}

void solve() {
  if(recursion(s.size() / 2)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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