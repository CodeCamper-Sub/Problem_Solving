#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
string s;
vector<ll> matched;

void init() {
  cin >> n >> s;
  matched.assign(n / 2, false);
}

void solve() {
  for(ll i = 0; i < n / 2; i++) {
    matched[i] = (s[i] == s[n - i - 1] ? 1 : 0);
  }
  if(*min_element(matched.begin(), matched.end()) == 1) {
    cout << "Yes\n";
    return;
  }
  ll i = 0;
  while(matched[i] == 1) i++;
  while(i < n && matched[i] == 0) {
    matched[i] = 1;
    i++;
  }
  if(*min_element(matched.begin(), matched.end()) == 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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