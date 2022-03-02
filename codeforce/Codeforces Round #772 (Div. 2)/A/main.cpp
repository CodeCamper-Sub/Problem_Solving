#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, a, answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        answer = 0;
        cin >> n;
        while (n--) {
            cin >> a;
            answer = answer | a;
        }
        cout << answer << '\n';
    }
    return 0;
}