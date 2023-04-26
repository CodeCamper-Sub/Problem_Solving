#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll mini, maxi;
vector<ll> 제곱ㄴㄴ;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> mini >> maxi;
  제곱ㄴㄴ.assign(maxi - mini + 1, -1);
  for(ll i = 2; i * i <= ll(1e13); i++) {
    for(ll j = mini / (i * i); i * i * j <= maxi; j++) {
      if(i * i * j < mini) continue;
      제곱ㄴㄴ[i * i * j - mini] = 1;
    }
  }
  ll answer = 0;
  for(ll i = 0; i < 제곱ㄴㄴ.size(); i++) {
    if(제곱ㄴㄴ[i] == -1) answer++;
  }

  cout << answer << '\n';
  
  return 0;
}