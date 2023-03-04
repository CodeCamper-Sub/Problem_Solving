#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a, b, c, d, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c >> d;

    t = a * 60 * 60 + b * 60 + c;
    t += d;
    t %= 60 * 60 * 24;
    
    cout << t / (60 * 60) << ' ';
    t %= 60 * 60;
    cout << t / 60 << ' ';
    t %= 60;
    cout << t;


    return 0;
}