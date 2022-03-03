#include <bits/stdc++.h>
using namespace std;

int t, n, answer;
int a[1000100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        answer = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 2; i <= n-2; i++) {
            if ( a[i-1] < a[i] && a[i] > a[i+1] ) {
                answer++;
                a[i+1] = max(a[i], a[i+2]);
            }
        }
        if ( a[n-2] < a[n-1] && a[n-1] > a[n] && n >= 3) {
            answer++;
            a[n] = a[n-1];
        }
        cout << answer << '\n';
        for(int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}