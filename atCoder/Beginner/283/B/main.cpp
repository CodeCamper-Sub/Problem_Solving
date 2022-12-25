#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll arr[100100];
ll N, Q, c, k ,x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> Q;
    for(ll i = 0; i < Q; i++) {
        cin >> c;
        if(c == 1) {
            cin >> k >> x;
            arr[k] = x;
        } else {
            cin >> k;
            cout << arr[k] << '\n';
        }
    }

    return 0;
}