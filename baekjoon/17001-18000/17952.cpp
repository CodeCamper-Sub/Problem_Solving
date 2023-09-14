#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, c, a, t;
vector<pair<ll, ll>> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    cin >> c;
    if(c == 1) {
      cin >> a >> t;
      st.push_back({a, t});
    }
    if(st.size()) {
      st.back().second -= 1;
      if(st.back().second == 0) {
        answer += st.back().first;
        st.pop_back();
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}