#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<pair<ll, ll>> s;
unordered_map<ll, ll> visited;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  s.resize(m);


  for(ll i = 0; i < m; i++) {
    cin >> s[i].first;
    s[i].second = i + 1;
  }

  sort(s.begin(), s.end());

  ll l = 0, r = 1;
  ll sum = s[l].first;

  while(r < m) {
    if(sum >= n && sum <= 2 * n) {
      cout << r - l << '\n';
      for(ll i = l; i < r; i++) cout << s[i].second << '\n';
      return 0;
    }
    if(sum + s[r].first <= 2 * n) {
      sum += s[r].first;
      r++;
    }
    else {
      while(l < r && sum + s[r].first > 2 * n) {
        sum -= s[l].first;
        l++;
      }
      if(l == r && sum + s[r].first > 2 * n) break;
      else {
        sum += s[r].first;
        r++;
      }
    }
  }
  if(sum >= n && sum <= 2 * n) {
    cout << r - l << '\n';
    for(ll i = l; i < r; i++) cout << i + 1 << '\n';
    return 0;
  }



  
  return 0;
}