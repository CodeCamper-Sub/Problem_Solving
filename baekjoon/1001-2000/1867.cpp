#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 1010
typedef long long ll;
using namespace std;

ll n, k, occupied[MAX], visited[MAX], max_matching;
vector<ll> e[MAX];

bool dfs(ll now) {
  for(ll next: e[now]) {
    if(visited[next]) continue;
    visited[next] = true;
    if(occupied[next] == -1 || dfs(occupied[next])) {
      occupied[next] = now;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  for(ll i = 0; i < k; i++) {
    ll x, y;
    cin >> x >> y;
    e[x].push_back(y);
  }

  fill(occupied, occupied + MAX, -1);
  max_matching = 0;
  for(ll i = 1; i <= n; i++) {
    fill(visited, visited + MAX, false);
    if(dfs(i)) max_matching++;
  }

  cout << max_matching << '\n';
  
  return 0;
}