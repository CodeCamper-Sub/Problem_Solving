#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, called[200200], a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> a;
    if(called[i] == 0) {
        called[a] = 1;
    }
  }

  ll answer = 0;
  for(ll i = 1; i <= n; i++) {
    if(called[i] == 0) answer++;
  }

  cout << answer << '\n';
  for(ll i = 1; i <= n; i++) {
    if(called[i] == 0) {
        cout << i << ' ';
    }
  }
  
  return 0;
}