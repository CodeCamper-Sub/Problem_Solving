#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, a;
ll arr[100100];
vector<ll> primes;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void calculate_primes() {
    bool visited[100100];
    for(ll i = 0; i * i <= 1000000000; i++) visited[i] = false;
    for(ll i = 2; i * i <= 1000000000; i++) {
        if(!visited[i]) {
            primes.push_back(i);
            for(ll j = i * 2; j * j <= 1000000000; j += i) visited[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    calculate_primes();
    
    while(tt--) {
        bool flag = false;
        cin >> n;
        set<ll> used_primes;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < primes.size() && primes[j] <= arr[i]; j++) {
                if(arr[i] % primes[j] == 0) {
                    if(used_primes.find(primes[j]) != used_primes.end()) {
                        flag = true;
                    } else {
                        used_primes.insert(primes[j]);
                    }
                    while(arr[i] % primes[j] == 0) {
                        arr[i] /= primes[j];
                    }
                }
            }
            if(arr[i] > 1) {
                if(used_primes.find(arr[i]) != used_primes.end()) {
                    flag = true;
                } else {
                    used_primes.insert(arr[i]);
                }
            }
        }
        if(flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}