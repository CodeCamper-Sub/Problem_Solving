#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n;
unordered_map<ll, ll> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  ll a, answer;
  answer = 0;
  while(n--) {
    cin >> a;
    if(m.find(a) != m.end()) {
        answer++;
        m.erase(a);
    } else {
        m[a] = 1;
    }
  }
  cout << answer << '\n';
  
  return 0;
}