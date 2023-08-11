#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct Square {
  ll x1, y1, x2, y2;
};

ll n;
vector<Square> squares;
vector<ll> parent;

ll Find(ll a) {
  if(parent[a] == a) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  parent[a] = b;
}

bool intersects(Square a, Square b) {
  if(a.x1 > a.x2) swap(a.x1, a.x2);
  if(b.x1 > b.x2) swap(b.x1, b.x2);
  return \
    a.x1 <= b.x2 && b.x1 <= a.x2 && \
    a.y1 <= b.y2 && b.y1 <= b.y2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  squares.resize(n);
  parent.resize(n);
  iota(parent.begin(), parent.end(), 0);
  for(auto& [x1, y1, x2, y2]: squares) {
    cin >> x1 >> y1 >> x2 >> y2;
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      if(Find(i) == Find(j) || !intersects(squares[i], squares[j])) continue;
      Union(i, j);
    }
  }

  ll answer = 0;
  for(ll i = 0; i < n; i++) if(parent[i] == i) answer++;


  cout << answer << '\n';

  
  return 0;
}