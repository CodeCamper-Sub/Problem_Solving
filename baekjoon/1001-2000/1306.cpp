#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
priority_queue<pair<ll, ll>> q;
vector<ll> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  a.resize(n);
  for(ll& a: a) cin >> a;
  for(ll i = 0; i < min(2 * m - 1, n); i++) {
    q.push({a[i], i});
  }

  for(ll i = m - 1; i + m - 1 < n; i++) {
    cout << q.top().first << ' ';
    if(i + m < n) q.push({a[i + m], i + m});
    while(q.size() && q.top().second <= (i - m + 1)) q.pop();
  }
  
  return 0;
}