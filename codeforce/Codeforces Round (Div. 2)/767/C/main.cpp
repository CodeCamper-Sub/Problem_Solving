#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tt;
    cin >> tt;
    while(tt--) {
        ll n, a[200200], occurence[200200];
        cin >> n;
        fill(occurence, occurence + n + 1, 0);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
            occurence[a[i]]++;
        }
        ll maximum = 0;
        for(ll i = 1; i <= n; i++) {
            if(occurence[i-1] > 0) {
                maximum = i;
            } else {
                break;
            }
        }
        set<ll> s;
        vector<ll> answer;
        answer.push_back(maximum);
        for(ll i = 0; i < n; i++) {
            if(a[i] < maximum) {
                s.insert(a[i]);
            }
            occurence[a[i]]--;
            if(s.size() == maximum) {
                maximum = 0;
                for(ll i = 1; i <= n + 1; i++) {
                    if(occurence[i-1] > 0) {
                        maximum = i;
                    } else {
                        break;
                    }
                }
                if(i < n - 1) {
                    answer.push_back(maximum);
                }
                s = set<ll>();
            }
        }
        // cout << "Answer(Case #" << tt << "):";
        cout << answer.size() << '\n';
        for(ll ans: answer) {
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}