#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M;
ll arr[550];
ll parent[550];
vector<tuple<ll, ll, ll>> e;
priority_queue<tuple<ll, ll, ll>> q;

ll find(ll node) {
    if(parent[node] == -1) {
        return node;
    } else {
        return parent[node] = find(parent[node]);
    }
}

void Union(ll a, ll b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

ll power(ll base, ll exponent) {
    if(exponent == 1) {
        return base % M;
    } else if(exponent % 2 == 0) {
        return power((base * base) % M, exponent / 2);
    } else {
        return power((base * base) % M, exponent / 2) * base % M;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    power(2, 3);
    for(ll i = 0; i <= N; i++) parent[i] = -1;

    for(ll i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(ll i = 1; i <= N; i++) {
        for(ll j = i + 1; j <= N; j++) {
            ll weight = (power(arr[i], arr[j]) + power(arr[j], arr[i])) % M;
            e.push_back({weight, i, j});
            q.push({weight, i, j});
        }
    }

    ll answer = 0;
    while(!q.empty()) {
        ll weight = get<0>(q.top());
        ll a = get<1>(q.top());
        ll b = get<2>(q.top());
        q.pop();
        if(find(a) != find(b)) {
            Union(a, b);
            answer += weight;
        }
    }

    cout << answer << '\n';

    return 0;
}