#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b;
  ll answer = 0;
  while(a != b) {
    if(a > b) swap(a, b);
    answer += b / a;
    b %= a;
    if(b == 0) {
      answer--;
      break;
    }
  }

  cout << answer << '\n';
  
  return 0;
}