#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

using Edge = tuple<ll, ll, ll>;
ll n, m, a, b, c, sum;
vector<ll> parent;
priority_queue<Edge, vector<Edge>, greater<Edge>> q;

ll Find(ll a) {
  if(parent[a] == -1) return a;
  return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  parent[a] = b;
  return;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  parent.assign(n + 1, -1);
  while(m--) {
    cin >> a >> b >> c;
    q.push({c, a, b});
    sum += c;
  }

  ll answer = 0;
  while(q.size()) {
    auto[c, a, b] = q.top();
    q.pop();
    if(Find(a) == Find(b)) continue;
    Union(a, b);
    answer += c;
  }

  bool is_valid = true;
  for(ll i = 1; i <= n; i++) {
    if(Find(1) != Find(i)) {
      is_valid = false;
      break;
    }
  }
  if(is_valid) {
    cout << sum - answer << '\n';
  } else {
    cout << -1 << '\n';
  }
  
  return 0;
}