#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, k;
string s;

void init() {
  cin >> k >> s;
}

void solve() {
  string origin = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
  bool answer = false;
  for(ll i = 0; i < origin.size(); i++) {
    if(origin[i] == s[0]) {
      bool is_valid = true;
      for(ll j = 0; j < s.size(); j++) {   
        if(origin[i + j] != s[j]) {
          is_valid = false;
          break;
        }
      }
      if(is_valid) answer = true;
    }
  }
  if(answer) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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