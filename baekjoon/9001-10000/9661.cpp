#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  if(n % 5 == 0 || n % 5 == 2) {
    cout << "CY\n";
  } else {
    cout << "SK\n";
  }
  
  return 0;
}