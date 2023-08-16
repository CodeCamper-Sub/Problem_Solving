#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, k;
unordered_map<ll, ll> mp;
vector<tuple<ll, ll, ll>> e;
vector<ll> parent;

ll Find(ll a) {
  if(parent[a] == a) return a;
  else return parent[a] = Find(parent[a]);
}

bool Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  if(a == b || (mp.count(a) && mp.count(b))) return false;
  if(mp.count(a)) swap(a, b);
  parent[a] = b;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> k;
  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  for(ll i = 0; i < k; i++) {
    ll x;
    cin >> x;
    mp[x]++;
  }

  e.resize(m);
  for(auto& [c, x, y]: e) {
    cin >> x >> y >> c;
  }
  sort(e.begin(), e.end());
  
  ll answer = 0;
  for(auto [c, x, y]: e) {
    if(Union(x, y)) {
      answer += c;
    }
  }

  cout << answer << '\n';
  
  return 0;
}