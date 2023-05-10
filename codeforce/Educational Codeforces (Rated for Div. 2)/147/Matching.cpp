#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;

void init() {
  cin >> s;
}

void solve() {
  ll cnt = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '?') cnt++;
  }
  ll answer = 1;
  if(s[0] == '0') {
    cout << 0 << '\n';
    return;
  }
  if(s[0] == '?') {
    answer *= 9;
    cnt--;
  }
  while(cnt) {
    answer *= 10;
    cnt--;
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