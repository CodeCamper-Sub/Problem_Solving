#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, q, next_called;
set<ll> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  next_called = 1;
  while(q--) {
    ll c;
    cin >> c;
    if(c == 1) {
      s.insert(next_called++);
    } else if(c == 2) {
      ll x;
      cin >> x;
      s.erase(x);
    } else {
      cout << *s.begin() << '\n';
    }
  }
  
  return 0;
}