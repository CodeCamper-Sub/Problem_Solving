#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, u, v;
vector<ll> e[200200];
ll ind[200200];
ll visited[200200];
ll start = INF;

void dfs(ll now) {
    for(ll i = 0; i < e[now].size(); i++) {
        ll next = e[now][i];
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

    if(m != n-1) {
        cout << "No";
        return 0;
    }

    for(ll i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }
    for(ll i = 1; i <= n; i++) {
        if(ind[i] == 1) {
            start = i;
            break;
        }
    }
    if(start == INF) {
        cout << "No\n";
        return 0;
    }
    dfs(start);
    for(ll i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}