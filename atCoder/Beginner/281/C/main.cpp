#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, t, sum;
ll arr[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    t %= sum;

    for(ll i = 1; i <= n; i++) {
        if(t < arr[i]) {
            cout << i << ' ' << t << '\n';
            return 0;
        } else {
            t -= arr[i];
        }
    }


    return 0;
}