#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<pair<ll, ll>> v;
map<ll, vector<ll>> m;
vector<ll> eat;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  eat.assign(n + 1, 0);
  v.resize(n);
  for (ll i = 0; i < n; i++) {
    ll d, c;
    cin >> d >> c;
    m[d].push_back(c);
  }

  ll answer = 0, previous_key = -1;
  priority_queue<ll> q;
  for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
    auto [key, value] = *iter;

    if (previous_key != -1) {
      ll t = min(ll(q.size()), previous_key - key);
      for (ll i = 0; i < t; i++) {
        answer += q.top();
        q.pop();
      }
    }

    for (ll i = 0; i < value.size(); i++)
      q.push(value[i]);
    previous_key = key;
  }

  ll t = min(ll(q.size()), previous_key);
  for (ll i = 0; i < t; i++) {
    answer += q.top();
    q.pop();
  }

  cout << answer << '\n';

  return 0;
}