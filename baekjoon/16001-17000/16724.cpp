#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<ll> parent;

ll flatten(ll y, ll x) {
  return y * m + x;
}

ll Find(ll a) {
  if(parent[a] == a) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  if(a == b) return;
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;

  parent.resize(n * m);
  iota(parent.begin(), parent.end(), 0);

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      if(c == 'L') {
        Union(flatten(i, j), flatten(i, j - 1));
      } else if(c == 'R') {
        Union(flatten(i, j), flatten(i, j + 1));
      } else if(c == 'U') {
        Union(flatten(i, j), flatten(i - 1, j));
      } else if(c == 'D') {
        Union(flatten(i, j), flatten(i + 1, j));
      }   
    }
  }

  vector<ll> v;
  for(ll i = 0; i < n * m; i++) v.push_back(Find(i));
  
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v.size() << '\n';

  
  
  return 0;
}