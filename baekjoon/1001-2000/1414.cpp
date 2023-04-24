#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
char c;
using Edge = tuple<ll, ll, ll>;
vector<ll> parent;
priority_queue<Edge, vector<Edge>, greater<Edge>> q; // {dist, u, v};

ll to_int(char c) {
  if(c >= 'a' && c <= 'z') {
    return c - 'a' + 1;
  } else {
    return c - 'A' + 27;
  }
}

ll Find(ll a) {
  if(parent[a] == -1) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  parent.assign(n, -1);
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> c;
      if(c == '0') continue;
      q.push({to_int(c), i, j});
      answer += to_int(c);
    }
  }

  while(q.size()) {
    auto [dist, u, v] = q.top();
    q.pop();
    if(Find(u) == Find(v)) continue;
    answer -= dist;
    Union(u, v);
  }

  for(ll i = 0; i < n; i++) {
    if(Find(0) != Find(i)) {
      cout << -1 << '\n';
      return 0;
    }
  }

  cout << answer << '\n';
  
  return 0;
}