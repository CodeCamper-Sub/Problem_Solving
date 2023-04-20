#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
string s;

void init() {
  cin >> s;
}

void solve() {
  ll answer = 0;
  if(s == "^") {
    cout << 1 << '\n';
    return;
  }
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '_') {
      if(i == 0)
        answer++;
      if(i == s.size() - 1 || s[i + 1] == '_') {
        answer++;
      }
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