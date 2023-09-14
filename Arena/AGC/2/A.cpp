#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  ll answer = 0;
  for(ll i = 1; i <= n; i++) {
    answer += i;
  }
  cout << answer << '\n';
  cout << answer * answer << '\n';
  answer = 0;
  for(ll i = 1; i <= n; i++) {
    answer += i * i * i;
  }
  cout << answer << '\n';
  
  return 0;
}