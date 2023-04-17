#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

int highest_bit_position(unsigned long long n) {
    return sizeof(n) * 8 - __builtin_clzll(n) - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true) {
    cin >> n;
    if(!n) break;
    vector<ll> v(n);
    ll result = 0;
    for(ll &i: v) {
        cin >> i;
        result ^= i;
    }
    #ifdef DEBUG
    cout << "\nAns: ";
    #endif
    if(result == 0) {
        cout << 0 << '\n';
        continue;
    }
    ll b = (1 << highest_bit_position(result));
    ll answer = 0;
    for(ll k: v) {
        if((k & b) == b) answer++;
    }
    cout << answer << '\n';
  }
  
  return 0;
}