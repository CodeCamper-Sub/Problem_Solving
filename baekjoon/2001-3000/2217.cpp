#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  l.resize(n);
  for(ll& l: l) cin >> l;
  sort(l.rbegin(), l.rend());

  ll answer = 0;
  for(ll i = 0; i < n; i++) {
     answer = max(answer, (l[i] * (i + 1)));
  }

  cout << answer << '\n';
  
  return 0;
}