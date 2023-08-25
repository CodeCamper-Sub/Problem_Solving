#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, r, g, b;
vector<vector<vector<vector<ll>>>> memo;

ll fact(ll n) {
  if(n == 0) return 1;
  return n * fact(n - 1);
}

ll combination(ll n, ll r) {
  return fact(n) / fact(n - r) / fact(r);
}

ll dfs(ll now, ll r, ll g, ll b) {
  if(now == n) return 1;
  if(memo[now][r][g][b] != -1) return memo[now][r][g][b];
  memo[now][r][g][b] = 0;
  ll& result = memo[now][r][g][b];

  // 장난감 하나씩
  if(r >= now + 1) result += dfs(now + 1, r - now - 1, g, b);
  if(g >= now + 1) result += dfs(now + 1, r, g - now - 1, b);
  if(b >= now + 1) result += dfs(now + 1, r, g, b - now - 1);

  // 장난감 두개씩
  if((now + 1) % 2 == 0 && r >= (now + 1) / 2 && g >= (now + 1) / 2) result += dfs(now + 1, r - (now + 1) / 2, g - (now + 1) / 2, b) * combination(now + 1, (now + 1) / 2);
  if((now + 1) % 2 == 0 && r >= (now + 1) / 2 && b >= (now + 1) / 2) result += dfs(now + 1, r - (now + 1) / 2, g, b - (now + 1) / 2) * combination(now + 1, (now + 1) / 2);
  if((now + 1) % 2 == 0 && g >= (now + 1) / 2 && b >= (now + 1) / 2) result += dfs(now + 1, r, g - (now + 1) / 2, b - (now + 1) / 2) * combination(now + 1, (now + 1) / 2);

  // 장난감 새개씩
  if((now + 1) % 3 == 0 && r >= (now + 1) / 3 && g >= (now + 1) / 3 && b >= (now + 1) / 3)
    result += dfs(now + 1, r - (now + 1) / 3, g - (now + 1) / 3, b - (now + 1) / 3) * combination(now + 1, (now + 1) / 3) * combination((now + 1) * 2 / 3, (now + 1) / 3);

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> r >> g >> b;

  memo.resize(n);
  for_each(memo.begin(), memo.end(), [](auto& cube) {
    cube.resize(r + 1);
    for_each(cube.begin(), cube.end(), [](auto& layer) {
      layer.assign(g + 1, vector<ll>(b + 1, -1));
    });
  });

  cout << dfs(0, r, g, b);
  
  return 0;
}