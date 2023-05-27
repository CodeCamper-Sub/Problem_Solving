#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, h, k;
string s;
map<pair<ll, ll>, ll> items;

bool go(ll y, ll x, ll now, ll health) {
  if(now == s.size()) return true;
  if(health == 0) return false;
  ll ny = y, nx = x;
  if(s[now] == 'L') {
    nx--;
  } else if(s[now] == 'R') {
    nx++;
  } else if(s[now] == 'U') {
    ny++;
  } else {
    ny--;
  }
  if(items.count({nx, ny}) && health - 1 < k) {
    items.erase({nx, ny});
    return go(ny, nx, now + 1, k);
  } else {
    return go(ny, nx, now + 1, health - 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> h >> k;
  cin >> s;
  for(ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    items[{x, y}]++;
  }

  if(go(0, 0, 0, h)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return 0;
}