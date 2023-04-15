#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> k;
  ll even = k / 2;
  ll odd = (k + 1) / 2;
  cout << even * odd << '\n';
  
  return 0;
}