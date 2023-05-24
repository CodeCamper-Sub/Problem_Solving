#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  if(n == 1) {
    cout << "B\n";
  } else {
    cout << "A\n";
  }
  
  return 0;
}