#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll H, M, A, B, C, D;
  cin >> H >> M;
  ll minute = H * 60 + M;
  while(true) {
    H = minute / 60;
    M = minute % 60;

    A = H / 10;
    B = H % 10;
    C = M / 10;
    D = M % 10;

    ll converted_hour = A * 10 + C;
    ll converted_minute = B * 10 + D;

    if(converted_hour >= 0 && converted_hour < 24 && converted_minute >= 0 && converted_minute < 60) {
      cout << H << ' ' << M << '\n';
      break;
    }
    minute += 1;
    minute %= 60 * 24;
  }
  

  return 0;
}