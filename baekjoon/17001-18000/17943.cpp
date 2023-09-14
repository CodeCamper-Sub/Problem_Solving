#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, q, c, x, y, d;
vector<ll> v, psum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> q;
  v.resize(n - 1);
  psum.resize(n - 1);
  for(ll& v: v) cin >> v;

  psum[0] = v[0];
  for(ll i = 1; i < n - 1; i++) psum[i] = psum[i - 1] ^ v[i];
  while(q--) {
    cin >> c >> x >> y;
    x--; y--;
    ll result = 0;
    if(x == y) {
      result = 0;
    } else if(x + 1 == y) {
      result = v[x];
    } else {
      if(x > 0) {
        result = psum[y - 1] ^ psum[x - 1];
      } else {
        result = psum[y - 1];
      }
    }

    if(c == 0) {
      cout << result << '\n';
    } else {
      cin >> d;
      cout << (d ^ result) << '\n';
    }
  }
  
  return 0;
}