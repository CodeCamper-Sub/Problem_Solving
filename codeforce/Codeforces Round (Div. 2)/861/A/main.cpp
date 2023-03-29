#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, a, b;

void init() {
  cin >> a >> b;
}

void solve() {
  string answer = "";
  ll maxiluck = -INF;
  for(ll i = a; i <= b; i++) {
    string s = to_string(i);
    ll maxi = -INF;
    ll mini = INF;
    for(ll j = 0; j < s.size(); j++) {
      maxi = max(maxi, 1ll * (s[j] - '0'));
      mini = min(mini, 1ll * (s[j] - '0'));
    }
    ll lucky = maxi - mini;
    if(lucky == 9) {
      cout << i << '\n';
      return;
    }
    if(lucky > maxiluck) {
      maxiluck = lucky;
      answer = s;
    }
  }

  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}