#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true) {
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    cout << (a > b ? "Yes" : "No") << '\n';
  }
  
  return 0;
}