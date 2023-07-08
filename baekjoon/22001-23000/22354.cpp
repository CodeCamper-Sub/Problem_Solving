#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

int N;
vector<ll> v;
vector<ll> vv;
char arr[400000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;
  for(ll i = 1; i <= N ; i++){
    cin >> arr[i];
  }
  ll tt = 0;
  for(ll i = 1; i <= N ; i++){
    ll input;
    cin >> input;
    tt = max(tt, input);
    if(arr[i] != arr[i+1]){
      v.push_back(tt);
      tt = 0;
    }
  }

  for(ll i = 1 ; i < v.size()-1; i++){
    vv.push_back(v[i]);
  }
  sort(vv.rbegin(), vv.rend());
  ll answer = 0;
  for(ll i = 0 ; i < (vv.size()+1)/2; i++){
    answer += vv[i];
  }
  cout << answer << "\n";
  
  return 0;
}