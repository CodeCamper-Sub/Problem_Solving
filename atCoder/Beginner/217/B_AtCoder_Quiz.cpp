#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string a, b, c;
string d[4] = {"ABC", "ARC", "AGC", "AHC"};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b >> c;
  for(ll i = 0; i < 4; i++) {
    if(a == d[i] || b == d[i] || c == d[i]) continue;
    cout << d[i] << '\n';
    return 0;
  }
  
  return 0;
}