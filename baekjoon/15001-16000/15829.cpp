#include <bits/stdc++.h>
#define MOD 1234567891
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> s;
  ll r = 1;
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    answer += (s[i] - 'a' + 1) * r;
    answer %= MOD;
    r *= 31;
    r %= MOD;
  }

  cout << answer << '\n';
  
  return 0;
}