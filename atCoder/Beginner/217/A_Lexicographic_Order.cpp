#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b;

  cout << (a < b ? "Yes" : "No");
  
  return 0;
}