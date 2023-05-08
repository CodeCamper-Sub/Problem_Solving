#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll q;
queue<ll> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> q;
  for(ll i = 0; i < q; i++) {
    ll c, x;
    cin >> c;
    if(c == 1) {
      cin >> x;
      v.push(x);
    } else if(c == 2) {
      if(pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << v.front() << '\n';
        v.pop();
      }
    } else {
      while(v.size() ) {
        pq.push(v.front());
        v.pop();
      }
    }
  }
  
  return 0;
}