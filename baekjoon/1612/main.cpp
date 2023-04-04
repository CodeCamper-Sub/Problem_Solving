#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N;
vector<ll> n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  ll nn = N;
  while(nn) {
    n.push_back(nn % 10);
    nn /= 10;
  }

  ll c = 0;
  ll zero_cnt = 0;
  for(ll digit = 0; true; digit++) {
    ll sum = 0;
    bool all_zero = true;
    for(ll i = 1; i < n.size() && digit - i >= 0 && digit - i < m.size(); i++) {
      if(m[m.size() - i] > 0) all_zero = false;
      sum += n[i] * m[m.size() - i];
    }
    if(digit > 0 && all_zero && c == 0) {
      break;
    }
    sum += c % 10;
    c /= 10;
    bool is_valid = false;
    for(ll k = 0; k <= 9; k++) {
      if((sum + k * n[0]) % 10 == 1) {
        c += (sum + k * n[0]) / 10;
        m.push_back(k);
        is_valid = true;
        break;
      }
    }
    if(!is_valid) {
      cout << -1 << '\n';
      return 0;
    }
  }

  cout << m.size() << '\n';
  
  return 0;
}