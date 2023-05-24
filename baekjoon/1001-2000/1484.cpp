#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll g;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> g;
  set<ll> answers;
  for(ll i = 1; i <= g; i++) {
    if(g % i) continue;
    if(((g / i) + i) % 2 || g / i == i) continue;
    answers.insert(((g / i) + i) / 2);
  }

  if(answers.empty()) {
    cout << -1 << '\n';
  } else{ 
    for(ll a: answers) {
      cout << a << '\n';
    }
  }
  
  return 0;
}