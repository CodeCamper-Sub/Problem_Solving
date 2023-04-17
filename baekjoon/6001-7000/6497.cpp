#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m, n, x, y, z, minimum, sum;
priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;

ll parent[200200];

ll find(ll a) {
  if(parent[a] == -1) {
    return a;
  } else {
    return parent[a] = find(parent[a]);
  } 
}

void combine(ll a, ll b) {
  a = find(a);
  b = find(b);
  parent[b] = a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true) {
    cin >> m >> n;

    if(m == 0 && n == 0) break;

    for(ll i = 0; i < m; i++) {
      parent[i] = -1;
    }

    while(!q.empty()) q.pop();
    sum = 0;
    minimum = 0;
    
    for(ll i = 0; i < n; i++) {
      cin >> x >> y >> z;
      q.push({z, x, y});
      sum += z;
    }

    while(!q.empty()) {
      z = get<0>(q.top());
      x = get<1>(q.top());
      y = get<2>(q.top());
      q.pop();
      if(find(x) != find(y)) {
        minimum += z;
        combine(x, y);
      }
    }

    cout << sum - minimum << '\n';
  }

  return 0;
}