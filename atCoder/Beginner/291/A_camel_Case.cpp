#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] > 'z' || s[i] < 'a') {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  
  return 0;
}