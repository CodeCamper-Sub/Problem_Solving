#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll k_i, y_i;
string s, k, y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  k = "KOREA";
  y = "YONSEI";

  cin >> s;
  k_i = 0;
  y_i = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == k[k_i]) {
      k_i++;
    }
    if(s[i] == y[y_i]) {
      y_i++;
    }
    if(k_i == k.size()) {
      cout << k << '\n';
      return 0;
    }
    if(y_i == y.size()) {
      cout << y << '\n';
      return 0;
    }
  }
  
  return 0;
}