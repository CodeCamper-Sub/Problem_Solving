//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

void testcase();

ll tt, a, b;

void swap(ll* a, ll* b) {
  ll temp = *a;
  *a = *b;
  *b = temp;
}

ll gcd(ll a, ll b) {
  if(a < b) {
    swap(&a, &b);
  }
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    testcase();
  }
  return 0;
}

void testcase() {
  cin >> a >> b;
  cout << a * b / gcd(a,b) << '\n';
}
