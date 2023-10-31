#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MAX 50050
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> dp;
vector<ll> squares;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  squares.push_back(0);
  while(squares.back() <= 50000) squares.push_back(ll(squares.size()) * ll(squares.size()));

  dp.assign(MAX, INF);
  dp[0] = 0;
  for(ll k: squares) {
    for(ll i = k; i < MAX; i++) {
      dp[i] = min(dp[i], dp[i - k] + 1);
    }
  }

  cout << dp[n];
  
  return 0;
}