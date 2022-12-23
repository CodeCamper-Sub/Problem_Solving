#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  ll answer = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == 'v') {
      answer += 1;
    } else {
      answer += 2;
    }
  }
  cout << answer << '\n';

  return 0;
}