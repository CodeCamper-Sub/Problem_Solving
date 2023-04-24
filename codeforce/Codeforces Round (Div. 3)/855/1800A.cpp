#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

void init() {
  cin >> n >> s;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i] - 'A' + 'a';
    }
  }
}

void solve() {
  ll seq = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(seq == 0) {
      if(s[i] == 'm') {
        seq = 1;
        continue;
      } else {
        cout << "NO\n";
        return;
      }
    } else if(seq == 1) {
      if(s[i] == 'm') {
        continue;
      } else if(s[i] == 'e') {
        seq = 2;
        continue;
      } else {
        cout << "NO\n";
        return;
      }
    } else if(seq == 2) {
      if(s[i] == 'e') {
        continue;
      } else if(s[i] == 'o') {
        seq = 3;
        continue;
      } else {
        cout << "NO\n";
        return;
      }
    } else if(seq == 3) {
      if(s[i] == 'o') {
        continue;
      } else if(s[i] == 'w') {
        seq = 4;
        continue;
      } else {
        cout << "NO\n";
        return;
      }
    } else {
      if(s[i] == 'w') {
        continue;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  
  if(seq == 4) {
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