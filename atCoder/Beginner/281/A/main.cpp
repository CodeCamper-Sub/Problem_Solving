#include <iostream>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i = n; i >= 0; i--) {
        cout << i << '\n';
    }

    return 0;
}