#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<vector<map<ll, ll>>> memo;

ll dfs(ll previous, ll now, ll status) {
  if(memo[previous][now].count(status)) return memo[previous][now][status];
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  memo.resize(3);
  for_each(memo.begin(), memo.end(), [](auto& layer) {
    layer.assign(21, map<ll, ll>());
  });

  
  return 0;
}