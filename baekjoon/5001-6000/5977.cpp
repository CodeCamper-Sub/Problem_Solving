#include <bits/stdc++.h>
#define INF 9999999999999999
typedef long long ll;
using namespace std;

ll n, k, sum, e, minimum;
ll dp[100100];
priority_queue<pair<ll ,ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q; // {value, index}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sum = 0;
  cin >> n >> k;
  for(ll i = 1; i <= n; i++) { 
    cin >> e;
    sum += e;
    if(i <= k + 1) {
      dp[i] = e;
    } else {
      dp[i] = q.top().first + e;
    }
    while(!q.empty() && ((i - q.top().second > k) || (q.top().first >= dp[i]))) {
      q.pop();
    }
    q.push({dp[i], i});
  }

  minimum = INF;
  for(ll i = n - k; i <= n; i++) {
    minimum = min(minimum, dp[i]);
  }

  cout << sum - minimum << '\n';
  
  return 0;
}