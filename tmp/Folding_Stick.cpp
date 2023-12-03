#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll N;
ll arr[101000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(ll i = 1; i <= N; i++){
    cin >> arr[i];
  }
  ll now = 0;
  ll tsum = 0;
  for(ll i = 1; i <= N; i++){
    tsum += arr[i];
    if(now <= tsum){
      now = tsum;
      tsum= 0;
    }
  }
  cout << now << "\n";
  
  
  return 0;
}