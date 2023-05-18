#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  vector<ll> binary;
  while(n) {
    binary.push_back(n % 2);
    n /= 2;
  }
  binary.push_back(0);
  ll cnt = 0;
  for(ll b: binary) {
    if(b) cnt++;
  }
  ll answer = 0;
  ll t = 1;
  for(ll i = 0; i < binary.size() - 1 && cnt > k; i++) {
    if(binary[i] == 1) {
      answer += t;
      binary[i + 1]++;
    } else if(binary[i] == 2) {
      binary[i + 1]++;
      cnt--;
    }
    t *= 2;
  }

  cout << answer << '\n';
  
  return 0;
}