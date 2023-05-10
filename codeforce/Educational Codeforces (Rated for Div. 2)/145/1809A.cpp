#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
string s;

void init() { cin >> s; }

void solve() {
  sort(s.begin(), s.end());
  ll cnt = 1;
  ll max_cnt = 0;
  for (ll i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      max_cnt = max(max_cnt, cnt);
      cnt = 1;
    }
  }
  max_cnt = max(max_cnt, cnt);
  if(max_cnt == 1) {
    cout << 4 << '\n';
  } else if(max_cnt == 2) {
    cout << 4 << '\n';
  } else if(max_cnt == 3) {
    cout << 6 << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    init();
    solve();
  }
  return 0;
}