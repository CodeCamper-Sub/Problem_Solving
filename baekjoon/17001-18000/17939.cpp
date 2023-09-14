#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> p, maxi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  p.resize(n);
  maxi.resize(n);
  for(ll& p: p) cin >> p;
  maxi.back() = p.back();
  for(ll i = n - 2; i >= 0; i--) {
    if(maxi[i + 1] < p[i]) {
      maxi[i] = p[i];
    } else {
      maxi[i] = maxi[i + 1];
    }
  }

  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    answer += maxi[i] - p[i];
  }

  cout << answer << '\n';
  
  return 0;
}