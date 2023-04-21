#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

set<pair<ll, ll>> s;
ll n, y, x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  char c;
  s.insert({0, 0});
  for(ll i = 0; i < n; i++) {
    cin >> c;
    if(c == 'L') {
      x -= 1;
    } else if(c == 'R') {
      x += 1;
    } else if(c == 'U') {
      y += 1;
    } else {
      y -= 1;
    }
    if(s.find({x, y}) != s.end()) {
      cout << "Yes\n";
      return 0;
    } else {
      s.insert({x, y});
    }
  }

  cout << "No\n";
  
  return 0;
}