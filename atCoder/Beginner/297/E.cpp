#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> q;
ll n, k, answer, cnt;
vector<ll> a;
unordered_map<ll, ll> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  a.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];

  q.push(0);
  m[0] = 1;
  while(true) {
    ll now = q.top();
    cnt++;
    if(cnt > k) {
      cout << now << '\n';
      return 0;
    }
    q.pop();
    for(ll i = 0; i < n; i++) {
      ll next = now + a[i];
      if(m.find(next) == m.end()) {
        m[next] = 1;
        q.push(next);
      }
    }
  }
  
  
  
  return 0;
}