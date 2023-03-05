#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, visited[200200];
vector<ll> e[200200];
vector<ll> path;

void dfs(ll now) {
    path.push_back(now);
    for(ll next: e[now]) {
        if(!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    bool is_valid = true;
    for(ll i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            visited[i] = true;
            dfs(i);
            ll v_cnt = path.size();
            ll e_cnt = 0;
            while(!path.empty()) {
                ll now = path.back();
                path.pop_back();
                e_cnt += e[now].size();
            }
            e_cnt /= 2;
            if(v_cnt != e_cnt) is_valid = false;
        }
    }

    if(is_valid) {
        cout << "Yes";
    } else {
        cout << "No\n";
    }


    return 0;
}