#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    if(i < 3) {
      cout << s[i];
    } else {
      cout << 0;
    }
  }
  
  return 0;
}