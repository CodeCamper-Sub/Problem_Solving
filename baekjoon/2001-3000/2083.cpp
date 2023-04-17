#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string name;
    ll age, weight;
    while(true) {
        cin >> name >> age >> weight;
        if(name == "#" && age == 0 && weight == 0) break;
        if(age > 17 || weight >= 80) {
            cout << name << " Senior\n";
        } else {
            cout << name << " Junior\n";
        }
    }

    return 0;
}