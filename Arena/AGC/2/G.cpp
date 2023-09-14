#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> a;
ll m;
vector<tuple<ll, ll, ll>> c;
map<vector<ll>, ll> comp;
vector<vector<pair<ll, ll>>> e;
vector<bool> is_ending;

ll fact(ll n) {
  if(n == 0) return 1;
  else return n * fact(n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
  cin >> m;
  c.resize(m);
  for(auto& [l, r, c]: c) {
    cin >> l >> r >> c;
    l--; r--;
  }

  vector<ll> per(n);
  iota(per.begin(), per.end(), 0);
  ll id = 0;
  e.resize(fact(n) + 1);
  is_ending.resize(fact(n) + 1);
  do {
    vector<ll> key = per;
    comp[key] = ++id;
    bool can_end = true;
    for(ll i = 0; i < ll(key.size()) - 1; i++) {
      if(a[key[i]] > a[key[i + 1]]) {
        can_end = false;
        break;
      }
    }
    is_ending[id] = can_end;
  } while(next_permutation(per.begin(), per.end()));

  for(auto [l, r, c]: c) {
    for(auto [key, _]: comp) {
      ll now = comp[key];
      vector<ll> next_key = key;
      swap(next_key[l], next_key[r]);
      ll next = comp[next_key];
      e[now].push_back({next, c});
    }
  }

  vector<ll> dist(id + 1, INF);
  dist[1] = 0;
  min_heap<pair<ll, ll>> q;
  q.push({0, 1});
  while(q.size()) {
    auto [now_d, now] = q.top();
    q.pop();
    if(dist[now] < now_d) continue;
    for(auto [next, cost]: e[now]) {
      if(dist[next] > dist[now] + cost) {
        dist[next] = dist[now] + cost;
        q.push({dist[next], next});
      }
    }
  }

  ll answer = INF;
  for(auto [_, id]: comp) {
    if(!is_ending[id]) continue;
    answer = min(answer, dist[id]);
  }

  if(answer == INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }

  
  return 0;
}