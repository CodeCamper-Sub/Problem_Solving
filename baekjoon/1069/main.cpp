#include <bits/stdc++.h>
#define INF 999999999999
#define square(x) (x * x)
typedef long long ll;
using namespace std;

ll X, Y, D, T;
double minimum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);

  cin >> X >> Y >> D >> T;
  minimum = 50000;

  for(ll i = 0; ; i ++) {
    ll d = D * i;
    double t = T * i;
    if(square(d) <= square(X) + square(Y)) {
      t += abs(sqrt(square(X) + square(Y)) - d);
      minimum = min(minimum, t);
    } else if (i >= 2) {
      minimum = min(minimum, t);
      break;
    } else {
      t += abs(sqrt(square(X) + square(Y)) - d);
      minimum = min(minimum, t);
    }
  }

  cout << minimum << '\n';

  return 0;
}