#include <bits/stdc++.h>
using namespace std;

int t, n, s, l;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int I = 1; I <= t; I++) {
        // init
        l = 0;
        vector<int> v;

        // input
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++) {
            if(l+1 <= v[i]) {
                l++;
            }
        }

        cout << "Case #" << I << ": " << l << '\n';
    }
    return 0;
}