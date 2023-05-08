#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;

void init() {
  cin >> s;
}

void solve() {
  bool is_palindrome = true;
  bool is_all_same = true;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] != s[s.size() - i - 1]) {
      is_palindrome = false;
    }
    if(i > 0 && s[i] != s[i - 1]) is_all_same = false;
  }
  if(!is_palindrome) {
    cout << s.size() << '\n';
  } else {
    if(is_all_same) {
      cout << -1 << '\n';
    } else {
      cout << s.size() - 1 << '\n';
    }
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