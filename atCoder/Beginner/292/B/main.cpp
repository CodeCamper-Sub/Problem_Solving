#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, q, c, x;
ll arr[110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for(ll i = 0; i < q; i++) {
        cin >> c >> x;
        if(c == 1) {
            arr[x] += 1;
        } else if(c == 2) {
            arr[x] += 2;
        } else {
            string answer = arr[x] >= 2 ? "Yes\n" : "No\n";
            cout << answer << '\n';
        }
    }

    return 0;
}