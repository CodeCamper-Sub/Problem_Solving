#include <bits/stdc++.h>
typedef long long ll;
#define INF 2100000000
using namespace std;

int t, c, m, y, k;
int minC, minM, minY, minK;
int sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int I = 1; I <= t; I++) {
        minC = INF;
        minM = INF;
        minY = INF;
        minK = INF;
        cout << "Case #" << I << ": ";
        for(int i = 1; i <= 3; i++) {
            cin >> c >> m >> y >> k;
            minC = min(minC, c);
            minM = min(minM, m);
            minY = min(minY, y);
            minK = min(minK, k);
        }
        if (minC + minM + minY + minK < 1000000) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            sum = 1000000;
            cout << minC << " ";
            sum -= minC;
            sum = max(0, sum);

            cout << (sum < minM ? sum : minM) << " ";
            sum -= minM;
            sum = max(0, sum);

            cout << (sum < minY ? sum : minY) << " ";
            sum -= minY;
            sum = max(0, sum);

            cout << (sum < minK ? sum : minK) << " ";
            cout << '\n';
        }
    }
    return 0;
}
