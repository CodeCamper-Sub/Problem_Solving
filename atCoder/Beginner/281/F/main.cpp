#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
ll arr[200200];
ll binary[200200][32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    for(ll i = 0; i < n; i++) {
        ll numerator = arr[i];
        for(ll j = 32; j >= 0; j--) {
            binary[i][j] = numerator % 2;
            numerator /= 2;
            if(numerator == 0) break;
        }
    }

    for(ll i = 0; i <= 32; i++) {
        bool flag = false;
        for(ll j = 1; j < n; j++) {
            if(binary[j][i] != binary[j-1][i]) {
                flag = true;
                break;
            }
        }
        if(flag) break;
        for(ll j = 0; j < n; j++) {
            binary[j][i] = 0;
        }
    }

    ll index = 0;
    for(ll i = 0; i <= 32; i++) {
        if(binary[n-1][i]) {
            index = i;
            break;
        }
    }

    ll answer = 0;
    ll k = 1;
    for(ll i = 1; i <= 32-index; i++) {
        k *= 2;
    }
    for(ll i = index; i <= 32; i++) {
        answer += k * binary[n-1][i];
        k /= 2;
        if(binary[n-1][i] != binary[n-2][i]) {
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}