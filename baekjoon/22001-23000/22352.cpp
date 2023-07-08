#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll N, M;
ll vis[50][50];
ll now;
ll nn;
ll arr1[50][50];
ll arr2[50][50];
ll dx[4] = {0,0,-1,1};
ll dy[4] = {1,-1,0,0};
ll ans = 0;
ll dfs(ll x, ll y){
  if(now != arr2[x][y]) ans = -1;
  for(ll i = 0 ; i < 4; i++){
    ll nx = x + dx[i];
    ll ny = y + dy[i];
    if(nx >=1 && ny >=1 && nx <= N && ny <= M && vis[nx][ny] == 0 && arr1[nx][ny] == nn){
      vis[nx][ny] = 1;
      dfs(nx, ny);
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for(ll i = 1; i <= N ; i++){
    for(ll j = 1 ;j  <= M ; j++){
      cin >> arr1[i][j];
    }
  }
  for(ll i = 1; i <= N ; i++){
    for(ll j = 1 ;j  <= M ; j++){
      cin >> arr2[i][j];
    }
  }
  ll cnt = 0;
  for(ll i = 1; i <= N ; i++){
    for(ll j = 1; j <= M ;j++){
      if(vis[i][j] == 0){
        now = arr2[i][j];
        nn = arr1[i][j];
        if(now != nn) cnt++;
        vis[i][j] = 1;
        dfs(i,j);
      }
    }
  }
  if(ans == 0 && cnt <= 1) cout << "YES\n";
  else cout << "NO\n";
  
  
  return 0;
}