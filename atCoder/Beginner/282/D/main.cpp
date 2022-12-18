#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, u, v;
vector<ll> e[200200];
ll visited[200200]; // 0: No, 1 : W , 2 : B
queue<pair<ll, ll>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<vector<pair<ll, ll>>> bipartite_nodes;

    for(ll i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            vector<pair<ll, ll>> nodes;
            bool is_bipartite = true;
            visited[i] = 1;
            nodes.push_back({i, 1});
            q.push({i, 1});
            while(!q.empty()) {
                ll now = q.front().first;
                ll now_color = q.front().second;
                q.pop();
                for(ll k = 0; k < e[now].size(); k++) {
                    ll next = e[now][k];
                    ll next_color = now_color == 1 ? 2 : 1;
                    if(visited[next] == 0) {
                        visited[next] = next_color;
                        nodes.push_back({next, next_color});
                        q.push({next, next_color});
                    } else if (visited[next] != next_color) {
                        is_bipartite = false;
                        break;
                    }
                }
                if(!is_bipartite) break;
            }
            if(is_bipartite) {
                bipartite_nodes.push_back(nodes);
            }
            while(!q.empty()) q.pop();
        }
    }
    
    ll answer = 0;
    
    ll all_cnt = 0;
    for(ll i = 0; i < bipartite_nodes.size(); i++) {
        all_cnt += bipartite_nodes[i].size();
    }
    if(all_cnt != n) {
        cout << 0 << '\n';
        return 0;
    }
    // for(ll i = 0; i < bipartite_nodes.size(); i++) {
    //     answer += bipartite_nodes[i].size() * (all_cnt - bipartite_nodes[i].size());
    // }
    // answer /= 2;

    for(ll i = 0; i < bipartite_nodes.size(); i++) {
        ll edge_cnt = 0;
        ll white_cnt = 0;
        ll black_cnt = 0;
        for(ll j = 0; j < bipartite_nodes[i].size(); j++) {
            ll now = bipartite_nodes[i][j].first;
            edge_cnt += e[now].size();
            if(bipartite_nodes[i][j].second == 1) {
                white_cnt++;
            } else {
                black_cnt++;
            }
        }
        // answer += white_cnt * black_cnt - edge_cnt / 2;
        answer += white_cnt * (n - white_cnt);
        answer += black_cnt * (n - black_cnt);
    }
    answer /= 2;
    answer -= m;

    cout << answer << '\n';

    return 0;
}