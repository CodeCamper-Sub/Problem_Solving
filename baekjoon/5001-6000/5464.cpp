#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<ll> r, w, p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  r.resize(n);
  w.resize(m);
  for(ll i = 0; i < n; i++) cin >> r[i];
  for(ll i = 0; i < m; i++) cin >> w[i];
  p.resize(n);

  queue<ll> waiting;
  ll parking_cnt = 0;
  ll answer = 0;
  for(ll T = 0; T < 2 * m; T++) {
    ll v;
    cin >> v;
    if(v > 0) {
      if(parking_cnt < n) {
        for(ll i = 0; i < n; i++) {
          if(p[i] == 0) {
            p[i] = v;
            answer += r[i] * w[v - 1];
            parking_cnt++;
            break;
          }
        }
      } else {
        waiting.push(v);
      }
    } else {
      v *= -1;
      for(ll i = 0; i < n; i++) {
        if(p[i] == v) {
          p[i] = 0;
          if(waiting.size()) {
            p[i] = waiting.front();
            answer += r[i] * w[waiting.front() - 1];
            waiting.pop();
          } else {
            parking_cnt--;
          }
        }
      }
    }
  }
  
  cout << answer << '\n';
  
  return 0;
}