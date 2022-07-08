#include <iostream>
typedef long long ll;
using namespace std;

ll t, n;
ll power_of_two[30];

void calculate_power_of_two() {
  power_of_two[0] = 1;
  for(int i = 1; i < 25; i++) {
    power_of_two[i] = power_of_two[i-1] * 2;
  }
}

void testcase() {
  cin >> n;
  cout << 2 << '\n';
  for(int i = 1; i <= n; i += 2) {
    for(int j = 0; i * power_of_two[j] <= n; j++) {
      cout << i * power_of_two[j] << ' ';
    }
  }
  cout << '\n';
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  calculate_power_of_two();
  
  cin >> t;
  while(t--) {
    testcase();
  }
  
  return 0;
}

