#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, a;
ll connected[110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        cin >> a;
        connected[a] = 1;
    }
    vector<ll> path;
    path.push_back(1);
    for(ll i = 1; i < n; i++) {
        if(connected[i]) {
            path.push_back(i+1);
        } else {
            while(!path.empty()) {
                cout << path.back() << ' ';
                path.pop_back();
            }
            path.push_back(i+1);
        }
    }
    while(!path.empty()) {
        cout << path.back() << ' ';
        path.pop_back();
    }
    

    return 0;
}