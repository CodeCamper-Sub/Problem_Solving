#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, Q, a, b, x;
vector<tuple<ll, ll, ll, ll>> v;
min_heap<tuple<ll, ll, ll, ll>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> Q;
  v.resize(n);
  ll id = 0;
  for(auto& [a, b, x, i]: v) {
    cin >> a >> b >> x;
    i = id++;
  }

  sort(v.begin(), v.end(), greater<>());
  for(ll i = 1; i <= n; i++) {
    while(v.size() && get<0>(v.back()) <= i) {
      auto [a, b, x, i] = v.back();
      q.push({i, a, b, x});
      v.pop_back();
    }
    while(q.size() && get<2>(q.top()) < i) q.pop();

    if(q.size()) {
      cout << get<3>(q.top()) << ' ';
    } else {
      cout << 0 << ' ';
    }
  }

  
  return 0;
}