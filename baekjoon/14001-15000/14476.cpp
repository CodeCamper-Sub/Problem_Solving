#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> a, l, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  l.resize(n);
  r.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  l[0] = a[0];
  for(ll i = 1; i < n; i++) {
    l[i] = gcd(l[i - 1], a[i]);
  }
  r[n - 1] = a[n - 1];
  for(ll i = n - 2; i >= 0; i--) {
    r[i] = gcd(r[i + 1], a[i]);
  }

  pair<ll, ll> answer;
  for(ll i = 0; i < n; i++) {
    ll g; 
    if(i == 0) {
      g = r[i + 1];
    } else if(i == n - 1) {
      g = l[i - 1];
    } else {
      g = gcd(l[i - 1], r[i + 1]);
    }
    if(a[i] % g == 0) continue;
    if(answer.first < g) {
      answer.first = g;
      answer.second = a[i];
    }
  }

  if(answer.first != 0) {
    cout << answer.first << ' ' << answer.second << '\n';
  } else {
    cout << -1 << '\n';
  }

  
  return 0;
}