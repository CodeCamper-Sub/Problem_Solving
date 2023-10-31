#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int N;




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  cin>>N;
  vector<pair<ll,ll>> info(N+1, {0, 0});

  vector<ll> arr(N + 1,0);
  vector<ll> sum(N,0);

  for(int i = 1 ;i < N; ++i){
    cin >> arr[i];
    sum[i] = sum[i-1] + arr[i];
  }

  for(int i = 1  ;i < N ;++i){
    cin >> info[i].first >> info[i].second;
  }

  pair<ll, ll> now = info[1]; // time, speed
  deque<pair<ll,ll>> q;
  for (int i = 1; i < N; ++i) {
       
    now.first += now.second * arr[i];
  }

  cout<<min(dp[N].first, now.first);

  return 0;
}