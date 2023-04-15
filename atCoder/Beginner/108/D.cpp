#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll L;

void to_three_digit(ll n, vector<ll> &result) {
  while (n) {
    result.push_back(n % 3);
    n /= 3;
  }
  reverse(result.begin(), result.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> L;
  vector<ll> three_L;
  to_three_digit(L, three_L);

  return 0;
}