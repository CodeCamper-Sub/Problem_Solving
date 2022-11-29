#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll T;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--) {
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
      cout << s[i];
    }
    for(ll i = s.size() - 1; i >= 0; i--) {
      cout << s[i];
    }
    cout << '\n';
  }

  return 0;
}