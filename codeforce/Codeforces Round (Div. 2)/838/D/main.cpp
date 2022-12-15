#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, g;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    while(tt--) {
        cin >> n;
        ll datum = 1;
        ll next = datum + 1;
        while(true) {
            set<ll> s;
            ll maximum = -INF;
            ll candidate;
            while(next <= n) {
                cout << "? " << datum << ' ' << next << '\n';
                cout.flush();
                cin >> g;
                if(g > maximum) {
                    maximum = g;
                    candidate = next;
                }
                if(s.find(g) != s.end()) {
                    break;
                } else {
                    s.insert(g);
                }
                next++;
            }
            if(next > n) {
                cout << "! " << datum << ' ' << next-1 << '\n';
                cout.flush();
                break;
            } else {
                datum = candidate;
                next = datum + 1;
            }
        }
        cin >> g;
        if(g == -1) { return 0; }
    }

    return 0;
}