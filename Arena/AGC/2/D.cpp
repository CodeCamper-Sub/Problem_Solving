#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, sum;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    if(a != 1 || (v.size() && v.back().first != 1)) {
      v.push_back({a, 1});
    } else {
      v.back().second++;
    }
  }

  queue<pair<ll, ll>> q; // 곱, 합
  ll answer = 0;
  for(ll i = 0; i < v.size(); i++) {
    q.push({1, 0});
    if(v[i].first != 1) {
      ll n = q.size();
      while(n--) {
        auto [a, b] = q.front(); q.pop();
        a *= v[i].first;
        b += v[i].first;
        if(a == b) answer++;
        if(a <= sum) {
          q.push({a, b});
        }
      }
    } else {
      ll n = q.size();
      while(n--) {
        
      }
    }
  }

  
  return 0;
}