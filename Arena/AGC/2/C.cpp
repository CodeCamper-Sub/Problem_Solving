#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  min_heap<ll> q;
  ll maxi = 0;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
    q.push(a[i]);
  }

  ll answer = (maxi - q.top());
  while(true) {
    ll next_answer = 0;
    ll now = q.top(); q.pop();
    now *= 2;
    if(maxi < now) {
      maxi = now;
      q.push(now);
      next_answer = maxi - q.top();
      for(ll i = 0; i <= n; i++) {
        answer = min(answer, next_answer);
        now = q.top(); q.pop();
        now *= 2;
        maxi = max(maxi, now);
        q.push(now);
        next_answer = maxi - q.top();
      }
      cout << answer << '\n';
      return 0;
    } else {
      q.push(now);
      next_answer = maxi - q.top();
      answer = min(answer, next_answer);
    }
  }

  cout << answer << '\n';

  
  return 0;
}