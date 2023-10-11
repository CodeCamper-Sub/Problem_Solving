#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

double a;
string unit;

void init() {
  cin >> a >> unit;
}

void solve() {
  if(unit == "kg") {
    cout << a * 2.2046 << " lb\n";
  } else if(unit == "lb") {
    cout << a * 0.4536 << " kg\n";
  } else if(unit == "l") {
    cout << a * 0.2642 << " g\n";
  } else { // unit == "g"
    cout << a * 3.7854 << " l\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed;
  cout.precision(4);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}