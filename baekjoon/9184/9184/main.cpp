//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll a, b, c;
ll memo[110][110][110];

ll w(ll a, ll b, ll c) {
  if(memo[a+50][b+50][c+50] != LONG_LONG_MIN) {
    return memo[a+50][b+50][c+50];
  }
  if(a <= 0 || b <= 0 || c <= 0) {
    return memo[a+50][b+50][c+50] = 1;
  } else if(a > 20 || b > 20 || c > 20) {
    return memo[a+50][b+50][c+50] = w(20, 20, 20);
  } else if(a < b && b < c) {
    return memo[a+50][b+50][c+50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
  } else {
    return memo[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(ll i = 0; i <= 100; i++) {
    for(ll j = 0; j <= 100; j++) {
      for(ll k = 0; k <= 100; k++) {
        memo[i][j][k] = LONG_LONG_MIN;
      }
    }
  }
  while(true) {
    cin >> a >> b >> c;
    if(a == -1 && b == -1 && c == -1) {
      break;
    }
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << '\n';
  }
  
  return 0;
}

