#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll t;
vector<ll> k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> t;
  if(t < 4) {
    cout << t << '\n';
    return 0;
  }
  t--;
  while(t) {
    k.push_back(t % 3);
    t /= 3;
  }

  for(ll i = 1; i < k.size() - 1; i++) {
    if(k[i] < 2) {
      k[i + 1] -= 1;
      k[i] += 3;
    }
  }

  ll answer = 1;
  for(ll i = 0; i < k.size(); i++) {
    answer += k[i];
  }

  cout << answer << '\n';

  return 0;
}