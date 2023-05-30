#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, c, m;
ll answer, sum;

vector<vector<pair<ll, ll>>> e;
map<ll, ll> truck;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> c >> m;
  e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    e[u].push_back({v, c});
  }

  answer = 0;
  sum = 0;
  for(ll i = 1; i <= n; i++) {
    // 짐 내리기
    if(truck.count(i)) {
      answer += truck[i];
      sum -= truck[i];
      truck[i] = 0;
      truck.erase(i);
    }
    for(auto &[dest, cost]: e[i]) {
      if(sum + cost <= c) {
        truck[dest] += cost;
        sum += cost;
      } else if(sum <= c) {
        truck[dest] += c - sum;
        cost -= c - sum;
        sum = c;
        
        ll made_space = 0;
        while(truck.size() && dest < truck.rbegin()->first && made_space < cost) {
          if(made_space + truck.rbegin()->second <= cost) {
            made_space += truck.rbegin()->second;
            truck.erase(truck.rbegin()->first);
          } else if(made_space <= cost) {
            truck.rbegin()->second -= cost - made_space;
            made_space = cost;
          }
        }
        truck[dest] += made_space;
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}