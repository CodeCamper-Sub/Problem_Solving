#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, visited[2020], visited_cnt, scc[2020], scc_cnt, answer, scc_visited[2020];
vector<ll> e[2020];
set<ll> scc_elements[2020], scc_e[2020];
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
        while(!path.empty()) {
            ll node = path.top();
            path.pop();
            scc[node] = scc_cnt;
            scc_elements[scc_cnt].insert(node);
            if(now == node) break;
        }
        scc_cnt++;
    }
    return result;
}

ll scc_dfs(ll now) {
    ll cnt = 0;
    for(ll next: scc_e[now]) {
        if(!scc_visited[next]) {
            cnt += scc_dfs(next);
        } else {
            cnt += scc_visited[next];
        }
    }

    answer += scc_elements[now].size() * cnt;
    return scc_visited[now] = scc_elements[now].size() + cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }

    fill(visited, visited + n + 1, -1);
    fill(scc, scc + n + 1, -1);

    for(ll i = 1; i <= n; i++) {
        if(visited[i] == -1) dfs(i);
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j: e[i]) {
            if(scc[i] != scc[j]) {
                scc_e[scc[i]].insert(scc[j]);
            }
        }
    }

    answer = 0;
    for(ll i = 0; i < scc_cnt; i++) {
        answer += scc_elements[i].size() * (scc_elements[i].size() - 1);
    }

    for(ll i = scc_cnt - 1; i >= 0; i--) {
        if(!scc_visited[i]) {
            scc_dfs(i);
        }
    }


    answer -= m;
    cout << answer << '\n';

    return 0;
}