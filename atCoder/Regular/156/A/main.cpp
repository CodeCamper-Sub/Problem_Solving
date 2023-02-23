#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, head_cnt;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    while(tt--) {
        cin >> n;
        cin >> s;

        #ifdef DEBUG
        cout << "ANS: ";
        #endif
        
        head_cnt = 0;
        for(ll i = 0; i < n; i++) {
            if(s[i] == '1') head_cnt++;
        }
        if(head_cnt % 2 == 1) {
            cout << -1 << '\n';
            continue;
        } else if (head_cnt > 2 || head_cnt == 0) {
            cout << head_cnt / 2 << '\n';
            continue;
        }

        bool corner_case_flag = false;
        for(ll i = 0; i < n - 1; i++) {
            if(s[i] == '1' && s[i+1] == '1') {
                corner_case_flag = true;
                break;
            }
        }
        if(!corner_case_flag) {
            cout << head_cnt / 2 << '\n';
            continue;
        }

        for(ll i = 0; i < n - 1; i++) {
            if(s[i] == '0' && s[i+1] == '0') {
                corner_case_flag = false;
                break;
            }
        }

        if(corner_case_flag) {
            cout << -1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }

    return 0;
}