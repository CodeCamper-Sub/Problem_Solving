#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
using ll = long long;
using namespace std;

ll n, k, _a, _b, _c, _d;
__uint128_t a, b, c, d;
priority_queue<__uint128_t> q[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> _a >> _b >> _c >> _d;
  a = _a; b = _b; c = _c; d = _d;
  for(ll i = 0; i < n; i++) {
    char t; 
    ll u;
    cin >> t >> u;
    if(t == 'A') q[0].push(u);
    else if(t == 'B') q[1].push(u);
    else if(t == 'C') q[2].push(u);
    else q[3].push(u);
  }

  for(ll i = 0; i < k; i++) {
    __uint128_t na = 0, nb = 0, nc = 0, nd = 0;
    if(q[0].size()) na = (a + q[0].top()) * b * c * d;
    if(q[1].size()) nb = a * (b + q[1].top()) * c * d;
    if(q[2].size()) nc = a * b * (c + q[2].top()) * d;
    if(q[3].size()) nd = a * b * c * (d + q[3].top());
    
    if(max4(na, nb, nc, nd) == na) {
      cout << "A " << ll(q[0].top()) << '\n';
      a += q[0].top();
      q[0].pop();
    } else if(max4(na, nb, nc, nd) == nb) {
      cout << "B " << ll(q[1].top()) << '\n';
      b += q[1].top();
      q[1].pop();
    } else if(max4(na, nb, nc, nd) == nc) {
      cout << "C " << ll(q[2].top()) << '\n';
      c += q[2].top();
      q[2].pop();
    } else if(max4(na, nb, nc, nd) == nd) {
      cout << "D " << ll(q[3].top()) << '\n';
      d += q[3].top();
      q[3].pop();
    }
  }
  
  return 0;
}