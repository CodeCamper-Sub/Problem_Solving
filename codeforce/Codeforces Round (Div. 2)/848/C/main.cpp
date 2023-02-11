#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll T;
vector<vector<ll>> combination[15];
vector<ll> path;

void get_combination(ll now, ll depth, ll start_depth) {
    path.push_back(now);
    if(depth == 0) {
        vector<ll> result = path;
        combination[start_depth].push_back(result);
    } else {
        for(ll i = now + 1; i <= 10-depth; i++) {
            get_combination(i, depth-1, start_depth);
        }
    }
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    combination[0].push_back(vector<ll>());
    for(ll i = 1; i <= 10; i++) {
        for(ll j = 0; j <= 10-i; j++) {
            get_combination(j, i - 1, i);
        }
    }
    cin >> T;
    while(T--) {
        ll n, k;
        cin >> n >> k;
        vector<char> used;
        bool visited[30];
        fill(visited, visited+30, false);
        string a, b;
        cin >> a;
        cin >> b;
        for(ll i = 0; i < a.size(); i++) {
            if(!visited[a[i]-'a']) {
                visited[a[i]-'a'] = true;
                used.push_back(a[i]);
            }
        }
        ll answer = 0;
        for(ll t = 0; t < combination[k].size(); t++) {
            ll partial_answer = 0;
            ll consequence = 0;
            bool can_ignore[30];
            fill(can_ignore, can_ignore+30, false);
            for(ll i = 0; i < combination[k][t].size(); i++) {
                if(combination[k][t][i] < used.size()) {
                    can_ignore[used[combination[k][t][i]]-'a'] = true;
                }
                
            }
            for(ll i = 0; i < a.size(); i++) {
                if(a[i] == b[i] || can_ignore[a[i]-'a']) {
                    consequence++;
                } else {
                    partial_answer += (consequence * (consequence + 1)) / 2;
                    consequence = 0;
                }
            }
            if(consequence) {
                partial_answer += (consequence * (consequence + 1)) / 2;
            }
            answer = max(answer, partial_answer);
        }
        cout << answer << '\n';
    }
    return 0;
}