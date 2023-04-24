#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll answer = -INF;
  cin >> n >> s;
  ll cnt = 0;
  for(ll i = 0; i < n; i++) {
    if(s[i] == 'o') {
      cnt++;
    } else {
      answer = max(answer, cnt);
      cnt = 0;
    }
  }

  answer = max(answer, cnt);
  if(answer == n || answer == 0) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }

  
  return 0;
}