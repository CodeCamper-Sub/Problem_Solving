#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;
ll a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  cin >> s;
  bool answer = true;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == 'T') {
      a++;
    } else {
      b++;
    }
    if(a > b) {
      answer = true;
    } else if(a < b) {
      answer = false;
    }
  }

  if(answer) {
    cout << "T";
  } else {
    cout << "A";
  }
  
  return 0;
}