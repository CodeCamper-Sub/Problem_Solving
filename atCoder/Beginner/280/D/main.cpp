#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

vector<ll> get_primes() {
    ll sieve[10010000];
    vector<ll> primes;
    for(ll i = 0; i < 10010000; i++) sieve[i] = -1;
    for(ll i = 2; i <= 10000000; i++) {
        if(sieve[i] == -1) {
            primes.push_back(i);
            for(ll j = i * 2; j <= 10000000; j += i) {
                sieve[j] = i;
            }
        }
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll K;
    vector<ll> dividers;
    vector<ll> primes = get_primes();
    cin >> K;
    for(ll i = 0; primes[i] * primes[i] <= K; i++) {
        if(K % primes[i] == 0) {
            dividers.push_back(primes[i]);
        }
    }
    if(dividers.empty()) {
        cout << K << '\n';
    } else {
        ll last_divider = K;
        for(ll i = 0; i < dividers.size(); i++) {
            while(last_divider % dividers[i] == 0) last_divider /= dividers[i];
        }
        if(last_divider > 1) dividers.push_back(last_divider);
        ll maximum = 0;
        for(ll i = 0; i < dividers.size(); i++) {
            ll k = K;
            ll exponent = 0;
            while(k % dividers[i] == 0) {
                exponent++;
                k /= dividers[i];
            }
            ll now = dividers[i];
            ll divider_cnt = 1;
            for(ll j = 2; divider_cnt < exponent; j++) {
                now = dividers[i] * j;
                divider_cnt++;
                ll J = j;
                while(J % dividers[i] == 0) {
                    divider_cnt++;
                    J /= dividers[i];
                }
            }
            maximum = max(maximum, now);
        }
        cout << maximum << '\n';
    }

    return 0;
}