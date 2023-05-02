#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string pre, in;

void dfs(ll now, ll left, ll right) {
  if(left > right) {
    return;
  } else if(left == right) {
    cout << pre[now];
    return;
  }
  ll k = left;
  while(in[k] != pre[now]) k++;
  dfs(now + 1, left, k - 1);
  dfs(now + k - left + 1, k + 1, right);
  cout << pre[now];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(cin >> pre >> in) {
    dfs(0, 0, in.size() - 1);
    cout << '\n';
  }
  
  return 0;
}