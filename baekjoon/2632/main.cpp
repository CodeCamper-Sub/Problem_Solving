#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m, n, target;
vector<ll> pizza[2], prefix_sum[2];
vector<vector<ll>> sum[2];
map<ll, ll> a_m, b_m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> target;
  cin >> m >> n;
  pizza[0].resize(m + 1);
  prefix_sum[0].resize(m + 1);
  prefix_sum[0][0] = 0;
  sum[0].assign(m + 1, vector<ll>(m + 1));
  pizza[1].resize(n + 1);
  prefix_sum[1].resize(n + 1);
  prefix_sum[1][0] = 0;
  sum[1].assign(n + 1, vector<ll>(n + 1));
  
  for(ll i = 1; i <= m; i++) {
    cin >> pizza[0][i];
    prefix_sum[0][i] = pizza[0][i] + prefix_sum[0][i - 1];
  }
  
  for(ll i = 1; i <= n; i++) {
    cin >> pizza[1][i];
    prefix_sum[1][i] = pizza[1][i] + prefix_sum[1][i - 1];
  }
  
  a_m[0] = 1;
  for(ll i = 1; i <= m; i++) {
    for(ll j = 1; j <= m; j++) {
      if(i < j) {
        a_m[prefix_sum[0][j] - prefix_sum[0][i - 1]]++;
      } else if(i == j) {
        a_m[pizza[0][i]]++;
      } else if(j < i - 1) {
        a_m[prefix_sum[0][m] - prefix_sum[0][i - 1] + prefix_sum[0][j]]++;
      }
    }
  }

  b_m[0] = 1;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(i < j) {
        b_m[prefix_sum[1][j] - prefix_sum[1][i - 1]]++;
      } else if(i == j) {
        b_m[pizza[1][i]]++;
      } else if(j < i - 1){
        b_m[prefix_sum[1][n] - prefix_sum[1][i - 1] + prefix_sum[1][j]]++;
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i <= target; i++) {
    answer += a_m[i] * b_m[target - i];
  }

  cout << answer << '\n';


  
  return 0;
}