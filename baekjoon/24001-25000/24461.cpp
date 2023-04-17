#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, a, b;
ll ind[100100];
vector<ll> e[100100], answer;
queue<ll> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n-1; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        ind[a]++;
        ind[b]++;
    }
    for(ll i = 0; i < n; i++) {
        if(ind[i] == 1) {
            q.push(i);
        }
    }

    while(q.size() > 2) {
        ll k = q.size();
        while(k--) {
            ll now = q.front(); q.pop();
            ind[now] = -1;
            for(ll i = 0; i < e[now].size(); i++) { 
                ll next = e[now][i];
                ind[next]--;
                if(ind[next] == 1) {
                    q.push(next);
                }
            }
        }
    }

    for(ll i = 0; i < n; i++) {
        if(ind[i] >= 0) {
            answer.push_back(i);
        }
    }

    for(ll i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}