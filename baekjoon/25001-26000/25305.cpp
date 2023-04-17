#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, x;
ll scores[1010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  for(ll i = 0; i < n; i++) {
    cin >> scores[i];
  }
  sort(scores, scores + n);
  cout << scores[n-k] << '\n';
  
  return 0;
}