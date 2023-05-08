#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
set<ll> s;

void init() {
  cin >> n;
  a.resize(n);
  s.clear();
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
}

void solve() {
  bool is_palindrome = true;
  for(ll i = 0; i < n; i++) {
    if(a[i] != a[n - i - 1]) {
      s.insert(abs(a[i] - a[n - i - 1]));
    }
  }
  if(s.size() == 0) {
    cout << 0 << '\n';
    return;
  }
  ll answer = *s.begin();
  for(ll s: s) {
    answer = gcd(answer, s);
  }

  cout << answer << '\n';
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