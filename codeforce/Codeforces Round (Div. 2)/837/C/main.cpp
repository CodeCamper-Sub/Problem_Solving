#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, a, partial_multi;
ll arr[100100];
set<ll> preliminaries;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void calculate_preliminaries() {
    bool visited[100100];
    for(ll i = 0; i <= 100000; i++) visited[i] = false;
    for(ll i = 2; i <= 100000; i++) {
        if(!visited[i]) {
            preliminaries.insert(i);
            for(ll j = 1; i * j <= 100000; j++) visited[i * j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    calculate_preliminaries();
    ll multipulation = 1;
    for(auto iter = preliminaries.begin(); iter != preliminaries.end(); iter++) {
        multipulation *= *iter;
        if(multipulation < 0) {
            cout << "HAHA!!!";
        }
    }
    while(tt--) {
        bool flag = false;
        cin >> n;
        partial_multi = 1;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(ll i = 0; i < n; i++) {
            if(gcd(partial_multi, arr[i]) != 1) {
                flag = true;
                break;
            }
            partial_multi *= arr[i];
        }
        if(flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}