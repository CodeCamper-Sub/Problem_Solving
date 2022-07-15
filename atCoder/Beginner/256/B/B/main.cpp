//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, a[110], p;
ll pieces[110];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
    for(ll j = 1; j <= i; j++) {
      pieces[j] += a[i];
    }
  }
  for(ll i = 1; i <= n; i++) {
    if(pieces[i] > 3) {
      p++;
    }
  }
  cout << p << '\n';
  
  return 0;
}

