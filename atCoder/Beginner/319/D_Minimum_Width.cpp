#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<ll> l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  l.resize(n);
  for(ll& l: l) cin >> l;

  ll left = 0, right = ll(1e15);
  while(left <= right) {
    ll mid = (left + right) / 2;
    ll now = 0, rows = 1;
    for(ll i = 0; i < n; i++) {
      if(l[i] > mid) {
        rows = INF;
        break;
      }

      if(now == 0) {
        now += l[i];
      } else {
        if(now + 1 + l[i] <= mid) {
          now += 1 + l[i];
        } else {
          rows++;
          now = 0;
          now += l[i];
        }
      }
    }
    if(rows <= m) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << left << '\n';
  
  return 0;
}