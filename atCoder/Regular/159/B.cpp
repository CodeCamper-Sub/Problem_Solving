#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a, b, answer;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b;
  if(a > b) swap(a, b);
  answer = 0;
  while(a > 0 && b > 0) {
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    if(b - a == 1) {
      answer += a;
      break;
    } else if(a == b) {
      answer += 1;
      break;
    }
    ll minimum_move = INF;
    ll minimum_i = -1;
    for(ll i = 2; i * i <= b - a; i++) {
      if((b - a) % i) continue;
      if(a % i == b % i) {
        if(minimum_move >= a % i && minimum_i < i) {
          minimum_move = min(minimum_move, a % i);
          minimum_i = i;
        }
      }
      if(a % ((b - a) / i) == b % ((b - a) / i)) {
        if(minimum_move >= a % ((b - a) / i) && minimum_i < (b - a) / i) {
          minimum_move = a % ((b - a) / i);
          minimum_i = (b - a) / i;
        }
      }
    }
    if(a % (b - a) == b % (b - a)) {
      if(minimum_move >= a % (b - a)) {
        minimum_move = min(minimum_move, a % (b - a));
        minimum_i = b - a;
      }
    }
    answer += minimum_move;
    a -= minimum_move;
    b -= minimum_move;
  }

  cout << answer << '\n';
  
  return 0;
}