#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll 에이, 비;

ll 일의_개수(ll 숫자) {
  ll 이의_제곱 = 1;
  ll 결과 = 0;
  while(이의_제곱 < (1e18)) {
    결과 += (숫자 - 이의_제곱 + 1) / (이의_제곱 * 2) * (이의_제곱 * 2) / 2;
    결과 += max(0ll, min((숫자 - 이의_제곱 + 1) % (이의_제곱 * 2), 이의_제곱));
    이의_제곱 *= 2;
  }
  return 결과;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> 에이 >> 비;
  cout << 일의_개수(비) - 일의_개수(에이 - 1) << '\n';
  
  return 0;
}