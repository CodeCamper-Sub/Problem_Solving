//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll a, b, c;
ll hour, minute;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b >> c;
  hour = a;
  minute = b;
  hour += c / 60;
  minute += c % 60;
  hour += minute / 60;
  minute %= 60;
  hour %= 24;
  
  cout << hour << ' ' << minute << '\n';
  
  return 0;
}

