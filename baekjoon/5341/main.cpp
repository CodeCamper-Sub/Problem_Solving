#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true) {
    cin >> n;
    if(!n) break;
    cout << n * (n + 1) / 2 << '\n';
  }
  
  return 0;
}