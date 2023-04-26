#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m, n, t, md, mx;
vector<pair<ll, ll>> shops;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n >> t;
  shops.resize(t);

  for(ll i = 0; i < t; i++) {
    cin >> shops[i].first >> shops[i].second;
  }

  cin >> md >> mx;
  ll answer = 0;
  for(auto [sd, sx]: shops) {
    ll partial_answer = -INF;
    if(md == sd) {
      partial_answer = abs(mx - sx);
    } else if((md == 1 && sd == 2) || (md == 2 && sd == 1)) {
      partial_answer = min(mx + sx, 2 * m - mx - sx) + n;
    } else if((md == 1 && sd == 3) || (md == 3 && sd == 1)) {
      partial_answer = mx + sx;
    } else if(md == 1 && sd == 4) {
      partial_answer = m - mx + sx;
    } else if(md == 2 && sd == 3) {
      partial_answer = mx + n - sx;
    } else if((md == 2 && sd == 4) || (md == 4 && sd == 2)) {
      partial_answer = m - mx + n - sx;
    } else if(md == 3 && sd == 2) {
      partial_answer = n - mx + sx;
    } else if((md == 3 && sd == 4) || (md == 4 && sd == 3)) {
      partial_answer = min(mx + sx, 2 * n - mx - sx) + m;
    } else if(md == 4 && sd == 1) {
      partial_answer = mx + m - sx;
    }
    answer += partial_answer;
  }

  cout << answer << '\n';
  
  return 0;
}