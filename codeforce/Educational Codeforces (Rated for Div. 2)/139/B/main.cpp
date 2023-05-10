#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n;
string s;
ll memo[30][30];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    cin >> n >> s;
    if(n <= 3) {
      cout << "NO" << '\n';
      continue;
    }
    bool flag = false;
    for(ll i = 0; i < 30; i++) for(ll j = 0; j < 30; j++) memo[i][j] = 0;
    memo[s[0]-'a'][s[1]-'a'] = 1;
    for(ll i = 2; i < s.size()-1; i++) {
      if(memo[s[i]-'a'][s[i+1]-'a'] == 1) {
        flag = true;
      } else {
        memo[s[i-1]-'a'][s[i]-'a'] = 1;
      }
    }
    if(flag) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}