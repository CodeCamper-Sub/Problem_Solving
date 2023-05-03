#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> ind, answers;
vector<vector<ll>> e;
queue<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  ind.assign(n + 1, 0);
  answers.assign(n + 1, 0);
  for(ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    ind[v]++;
  }

  for(ll i = 1; i <= n; i++) {
    if(ind[i] == 0) {
      q.push(i);
    }
  }

  for(ll i = 1; q.size(); i++) {
    ll n = q.size();
    while(n--) {
      ll now = q.front();
      q.pop();
      answers[now] = i;
      for(ll next: e[now]) {
        ind[next]--;
        if(ind[next] == 0) {
          q.push(next);
        }
      }
    }
  }

  for(ll i = 1; i <= n; i++) {
    cout << answers[i] << ' ';
  }
  
  return 0;
}