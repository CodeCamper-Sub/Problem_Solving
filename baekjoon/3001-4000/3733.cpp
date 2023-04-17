#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(cin >> n >> s) {
    cout << s / (n + 1) << '\n';
  }
  
  return 0;
}