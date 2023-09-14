#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9+7);
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll h, x;
ll mul;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> x;
  mul = x;
  ll answer = 0;
  for(ll i = 0; i < h; i++) {
    ll c;
    cin >> c;
    answer += c * mul % MOD;
    answer %= MOD; 
    mul *= x;
    mul %= MOD;
  }

  cout << answer << '\n';
  
  return 0;
}