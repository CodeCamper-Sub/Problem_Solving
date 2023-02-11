#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, b, x;
ll a[100100], grid[100100], visited[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    fill(grid, grid+100100, 1);
    for(ll i = 0; i < m; i++) {
        cin >> b;
        grid[b] = 0;
    }
    
    cin >> x;

    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
        ll now = q.front(); q.pop();
        for(ll i = 0; i < n; i++) {
            ll next = now + a[i];
            if(next > x) break;
            if(!visited[next] && grid[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if(visited[x]) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    return 0;
}