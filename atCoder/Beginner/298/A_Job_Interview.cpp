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
  ll good = 0, poor = 0;
  for(ll i = 0; i < n; i++) {
    if(s[i] == 'o') good++;
    if(s[i] == 'x') poor++;
  }

  if(good > 0 && poor == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  
  return 0;
}