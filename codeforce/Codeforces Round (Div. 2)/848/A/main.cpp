#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        ll n, a[100100];
        ll sum = 0;
        ll flag = 2;
        cin >> n;
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for(ll i = 0; i < n-1; i++) {
            if(a[i] == -1 && a[i+1] == -1) 
                flag = 0;
            else if(a[i] == -1 && a[i+1] == 1) 
                flag = min(flag, 1ll);
            else if(a[i] == 1 && a[i+1] == -1) 
                flag = min(flag, 1ll);
        }
        if(flag == 0) {
            cout << sum + 4 << '\n';
        } else if(flag == 1) {
            cout << sum << '\n';
        } else {
            cout << sum - 4 << '\n';
        }
    }
    return 0;
}