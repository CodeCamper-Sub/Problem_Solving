#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, answer;
string s;

void init() {
  cin >> s;
  answer = 0;
}

void solve() {
  ll maximum = 0, now = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '1') {
      now++;
    } else {
      maximum = max(maximum, now);
      now = 0;
    }
  }
  maximum = max(maximum, now);
  if(maximum == 0) {
    cout << 0 << '\n';
    return;
  } else if(maximum == s.size()) {
    cout << s.size() * s.size() << '\n';
    return;
  }

  if(maximum % 2 == 0) {
    answer = (maximum / 2) * (maximum / 2 + 1);
  } else {
    answer = (maximum / 2 + 1) * (maximum / 2 + 1);
  }

  ll left = 0;

  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '0') break;
    left++;
  }

  ll right = 0;
  for(ll i = s.size() - 1; i >= 0; i--) {
    if(s[i] == '0') break;
    right++;
  }
  
  maximum = max(maximum, left + right);

  if(maximum % 2 == 0) {
    answer = (maximum / 2) * (maximum / 2 + 1);
  } else {
    answer = (maximum / 2 + 1) * (maximum / 2 + 1);
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