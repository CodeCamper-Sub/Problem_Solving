#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
min_heap<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    q.push(x);
  }

  ll answer = 0;
  while(q.size()) {
    if(q.size() <= 1) break;
    ll a = q.top(); q.pop();
    ll b = q.top(); q.pop();
    answer += a + b;
    q.push(a + b);
  }

  cout << answer << '\n';
  
  return 0;
}