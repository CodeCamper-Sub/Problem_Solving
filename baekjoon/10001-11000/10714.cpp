#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
vector<vector<ll>> dp, visited;
queue<pair<ll, ll>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
  
  dp.assign(n + 1, vector<ll>(n + 1, 0));
  visited.assign(n + 1, vector<ll>(n + 1, false));

  for(ll i = 0; i < n; i++) {
    dp[i][i] = 0;
    visited[i][i] = true;
    q.push({i, i});
  }

  while(q.size()) {
    auto [start, end] = q.front();
    q.pop();
    // 마지막 케이크를 가져가는 상황인 경우
    if((end - start + n) % n == n - 1) {
      dp[0][n] = max(dp[0][n], dp[start][end] + a[end]);
      continue;
    }

    // start - 1 가져가기
    ll cake = a[(start - 1 + n) % n];
      // start - 2와 end를 비교
    if(a[(start - 2 + n) % n] < a[end]) {
      ll nstart = (start - 1 + n) % n;
      ll nend = (end + 1) % n;
      dp[nstart][nend] = max(dp[nstart][nend], dp[start][end] + cake);
      if(!visited[nstart][nend]) {
        visited[nstart][nend] = true;
        q.push({nstart, nend});
      }
    } else if(a[(start - 2 + n) % n] > a[end]) {
      ll nstart = (start - 2 + n) % n;
      ll nend = end;
      dp[nstart][nend] = max(dp[nstart][nend], dp[start][end] + cake);
      if(!visited[nstart][nend]) {
        visited[nstart][nend] = true;
        q.push({nstart, nend});
      }
    } else {
      dp[0][n] = max(dp[0][n], dp[start][end] + cake);
    }

    // end 가져가기
    cake = a[end];
      // start - 1과 end + 1을 비교
    if(a[(start - 1 + n) % n] < a[(end + 1) % n]) {
      ll nstart = start;
      ll nend = (end + 2) % n;
      dp[nstart][nend] = max(dp[nstart][nend], dp[start][end] + cake);
      if(!visited[nstart][nend]) {
        visited[nstart][nend] = true;
        q.push({nstart, nend});
      }
    } else if(a[(start - 1 + n) % n] > a[(end + 1) % n]) {
      ll nstart = (start - 1 + n) % n;
      ll nend = (end + 1) % n;
      dp[nstart][nend] = max(dp[nstart][nend], dp[start][end] + cake);
      if(!visited[nstart][nend]) {
        visited[nstart][nend] = true;
        q.push({nstart, nend});
      }
    } else {
      dp[0][n] = max(dp[0][n], dp[start][end] + cake);
    }
  }

  cout << dp[0][n] << '\n';
  
  return 0;
}