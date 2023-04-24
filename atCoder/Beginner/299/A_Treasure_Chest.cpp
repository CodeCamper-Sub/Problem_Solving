#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> s;
  ll phase = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '|' && phase == 0) {
      phase = 1;
    } else if(s[i] == '*' && phase == 1) {
      phase = 2;
    } else if(s[i] == '|' && phase == 2) {
      phase = 3;
    }
  }

  if(phase == 3) {
    cout << "in";
  } else {
    cout << "out";
  }
  
  return 0;
}