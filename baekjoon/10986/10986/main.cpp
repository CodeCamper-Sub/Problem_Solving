//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, m, a[1001000];
ll sum[1001000], num[1010], answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = (sum[i-1] + a[i] % m) % m;
  }
  for(ll i = 0; i <= n; i++) {
    num[sum[i]]++;
  }
  for(ll i = 0; i < m; i++) {
    answer += num[i] * (num[i] - 1) / 2;
  }
  cout << answer << '\n';
  
  return 0;
}

