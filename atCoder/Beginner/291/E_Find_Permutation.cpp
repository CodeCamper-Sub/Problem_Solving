#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, x, y;
vector<vector<ll>> e;
vector<ll> ind, visited;
queue<ll> q;
vector<ll> result;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.assign(n + 1, vector<ll>());
  ind.assign(n + 1, 0);
  for(ll i = 0; i < m; i++) {
    cin >> x >> y;
    e[x].push_back(y);
    ind[y]++;
  }
  ll root = -1;
  for(ll i = 1; i <= n; i++) {
    if(ind[i] == 0) {
      result.push_back(i);
      q.push(i);
    }
  }
  while(q.size()) {
    if(q.size() > 1) {
      cout << "No\n";
      return 0;
    }
    ll now = q.front();
    q.pop();
    for(ll next: e[now]) {
      ind[next]--;
      if(ind[next] == 0) {
        result.push_back(next);
        q.push(next);
      } else if(ind[next] < 0) {
        cout << "No\n";
        return 0;
      }
    }
  }

  if(result.size() != n) {
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";
  vector<ll> answer(n + 1);
  for(ll i = 0; i < result.size(); i++) {
    answer[result[i]] = i + 1;
  }

  for(ll i = 1; i <= n; i++) {
    cout << answer[i] << ' ';
  }
  
  return 0;
}