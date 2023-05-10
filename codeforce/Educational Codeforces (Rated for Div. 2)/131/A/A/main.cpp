#include <iostream>
typedef long long ll;
using namespace std;

ll t, a;

ll testcase() {
  ll grass_count = 0;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> a;
      if(a == 1) {
        grass_count++;
      }
    }
  }
  if(grass_count == 0) {
    return 0;
  } else if(grass_count == 4) {
    return 2;
  } else {
    return 1;
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> t;
  while(t--) {
    cout << testcase() << '\n';
  }
  
  return 0;
}
