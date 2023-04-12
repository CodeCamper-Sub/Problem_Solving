#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  while(n--) {
    ll a;
    cin >> a;
    if(a % 2 == 0){ 
      cout << a << ' ';
    }
  }
  
  return 0;
}