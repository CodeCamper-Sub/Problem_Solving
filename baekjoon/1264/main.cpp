#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  while(true) {
    ll answer = 0;
    getline(cin, s);
    if(s == "#") break;
    for(ll i = 0; i < s.size(); i++) {
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') answer++;
    }
    cout << answer << '\n';
  }

  return 0;
}