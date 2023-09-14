#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, k;
vector<ll> x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  x.resize(n);
  ll left = 0, right = 0;
  for(ll& x: x) {
    cin >> x;
    right += x;
  }

  while(left <= right) {
    ll mid = (left + right) / 2;
    
    ll partial_sum = 0;
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
      if(partial_sum + x[i] >= mid) {
        cnt++;
        partial_sum = 0;
      } else {
        partial_sum += x[i];
      }
    }
    if(cnt >= k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << right << '\n';
  
  return 0;
}