#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

set<ll> snuke;
ll k;
vector<ll> s, ten_digits, nine_digits;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  s.assign(10000001, 0);
  for(ll i = 1; i <= 10000000; i++) {
    ll n = i;
    while(n) {
      s[i] += n % 10;
      n /= 10;
    }
  }
  ten_digits.push_back(1);
  nine_digits.push_back(0);
  for(ll i = 1; i <= 18; i++) {
    ten_digits.push_back(ten_digits.back() * 10);
  }
  for(ll i = 1; i <= 18; i++) {
    nine_digits.push_back(nine_digits.back() * 10 + 9);
  }

  for(ll i = 0; i <= 15; i++) { // 뒤에 고정된 9의 개수
    for(ll j = 1; log10(j) + i <= 15; j++) {
      ll now = j * ten_digits[i] + nine_digits[i];
      ll sum = s[j] + 9 * i;
      if(now <= sum * ten_digits[i]) {
        snuke.insert(now);
      } else {
        break;
      }
    }
  }


  
  cin >> k;
  auto iter = snuke.begin();
  while(k--) {
    cout << *iter << '\n';
    iter++;
  }
  
  return 0;
}