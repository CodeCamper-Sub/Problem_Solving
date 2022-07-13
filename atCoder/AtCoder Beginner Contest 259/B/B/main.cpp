//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll a, b;
double r, d, theta, adjusted_theta, x, y;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
  
  cin >> a >> b >> d;
  
  if(a == 0 && b == 0) {
    cout << "0 0\n";
    return 0;
  }
  
  r = sqrt(a * a + b * b);
  
  theta = acos(double(a) / r);
  
  if(b < 0) {
    theta = 2 * M_PI - theta;
  }
  x = cos(theta + d * (M_PI / 180)) * r;
  y = sin(theta + d * (M_PI / 180)) * r;
  
  cout << x << ' ' << y << '\n';
  
  return 0;
}

