#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<pair<ll, ll>> v;
vector<ll> c;
ll n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  v.resize(n);
  c.resize(k);
  for(ll i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  for(ll i = 0; i < k; i++) {
    cin >> c[i];
  }

  sort(v.begin(), v.end());
  sort(c.begin(), c.end());
  priority_queue<ll> q;
  ll answer = 0;
  ll j = 0;
  for(ll i = 0; i < k; i++) {
    while(j < n && v[j].first <= c[i]) q.push(v[j++].second);
    if(q.size()) {
      answer += q.top();
      q.pop();
    }
  }
  cout << answer << '\n';

  return 0;
}