#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, m, visited[200200], cycle_cnt, non_cycle_cnt;
vector<ll> e[200200];

bool dfs(ll now) { 
    bool result = e[now].size() == 2;
    for(ll next: e[now]) {
        if(!visited[next]) {
            visited[next] = true;
            result &= dfs(next);
        }
    }
    return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 0; i < m; i++) {
    ll a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    e[a].push_back(c);
    e[c].push_back(a);
  }

  for(ll i = 1; i <= n; i++) {
    if(!visited[i]) {
        visited[i] = true;
        bool is_cycle = dfs(i);
        if(is_cycle) cycle_cnt++;
        else non_cycle_cnt++;
    }
  }

  cout << cycle_cnt << ' ' << non_cycle_cnt << '\n';
  
  return 0;
}