#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
string s, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> s >> t;
  for(ll i = 0; i < n; i++) {
    if(s[i] == t[i]) continue;
    if(s[i] == 'o' && t[i] == '0') continue;
    if(s[i] == '0' && t[i] == 'o') continue;
    if(s[i] == '1' && t[i] == 'l') continue;
    if(s[i] == 'l' && t[i] == '1') continue;
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";
  
  return 0;
}