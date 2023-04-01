#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, a, visited[200200], visited_cnt, scc[200200], scc_cnt;
vector<ll> scc_elements[200200];
vector<ll> e[200200];
stack<ll> path;

ll dfs(ll now) {
    visited[now] = visited_cnt++;
    path.push(now);
    ll result = visited[now];
    for(ll next: e[now]) {
        if(visited[next] == -1) {
            result = min(result, dfs(next));
        } else if(scc[next] == -1) {
            result = min(result, visited[next]);
        }
    }
    if(result == visited[now]) {
        while(path.size()) {
            ll node = path.top();
            path.pop();
            scc_elements[scc_cnt].push_back(node);
            scc[node] = scc_cnt;
            if(now == node) break;
        }
        scc_cnt++;
    }
    return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> a;
    e[i].push_back(a);
  }

  fill(visited, visited + n + 1, -1);
  fill(scc, scc + n + 1, -1);
  for(ll i = 1; i <= n; i++) {
    if(visited[i] == -1) dfs(i);
  }

  ll answer = 0;
  for(ll i = 0; i < scc_cnt; i++) {
    if(scc_elements[i].size() > 1) {
        answer += scc_elements[i].size();
    } else {
        ll node = scc_elements[i][0];
        if(e[node][0] == node) answer++;
    }
  }

  cout << answer << '\n';
  
  return 0;
}