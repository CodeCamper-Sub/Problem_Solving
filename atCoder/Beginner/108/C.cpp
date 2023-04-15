#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  ll answer = (n / k) * (n / k) * (n / k);

  if(k % 2 == 0) {
    // %k가 k / 2인 애들의 개수
    ll cnt = (n / k);
    if(n % k >= k / 2) cnt++;
    answer += cnt * cnt * cnt;
  }

  cout << answer << '\n';

  
  return 0;
}