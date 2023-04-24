#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, answer;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll nn;
  cin >> nn;
  n = nn;
  while(n) {
    answer += n % 10;
    n /= 10;
  }

  if(nn % answer) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  
  return 0;
}