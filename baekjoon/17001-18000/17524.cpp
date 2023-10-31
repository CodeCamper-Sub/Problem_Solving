#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll N, K;
vector<ll> v;
vector<pair<ll, ll>> arr;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for(ll i = 1; i <= N; i++){
    ll a, b;
    cin >> a >> b;
    arr.push_back({a,b});
  }
  sort(arr.begin(), arr.end());
  
  ll answer = INT_MAX;
  if(K == 1){
    ll ans = 0;
    for(ll i = 40 ; i<= 100; i++){
      for(ll j = 0; j < N; j++){
        ans = max(ans,(arr[j].first-i)*arr[j].second);
      }
    }
    answer = min(answer , ans+30);
  }
  else if(K== 2){
    ll ans = 0;
    
    for(ll i = 40; i <= 100; i++){
      for(ll j = i+1; j<= 100; j++){
        ll isok = 1;
        ll chk1 = 0;
        ll chk2 = 0;
        ll no1 = 0;
        ll no2 = 0;
        for(ll k = 0; k< N; k++){
          ll tmp1 = (arr[k].first-i)*arr[k].second;
          ll tmp2 = (arr[k].first-j)*arr[k].second;
          if(tmp1<0) tmp1 = INT_MAX;
          if(tmp2<0) tmp2= INT_MAX;
          if(tmp1 == INT_MAX && tmp2 == INT_MAX){
            isok = 0;
            break;
          }
          tmp1 -= no1;
          if(chk1==0) tmp1+=30;
          tmp2 -= no2;
          if(chk2==0) tmp2+=30;
          if(tmp1<=0) continue;
          if(tmp2<=0) continue;
          if(tmp1 <= tmp2){
            no1 = no1+tmp1;
            if(chk1 == 0) no1 -= 30;
            chk1 = 1;
          }
          else{
            no2 = no2+tmp2;
            if(chk2 == 0) no2 -= 30;
            chk2=1;
          }
        }
        if(!isok) continue;
        ans = no1+no2;
        answer = min(answer ,ans+chk1*30 + chk2*30);
      }
    }
    
  }
  else{
    ll ans = 0;
    for(ll i = 40; i <= 100; i++){
      for(ll j = i+1; j<= 100; j++){
        for(ll k = j+1; k<= 100; k++){
          ll isok = 1;
          ll chk1 = 0;
          ll chk2 = 0;
          ll chk3 = 0;
          ll no1 = 0;
          ll no2 = 0;
          ll no3 = 0;
          for(ll p = 0; p < N; p++){
            ll tmp1 = (arr[p].first-i)*arr[p].second;
            ll tmp2 = (arr[p].first-j)*arr[p].second;
            ll tmp3 = (arr[p].first-k)*arr[p].second;
            if(tmp1<0) tmp1 = INT_MAX;
            if(tmp2<0) tmp2= INT_MAX;
            if(tmp3<0) tmp3 = INT_MAX;
            if(tmp1 == INT_MAX && tmp2 == INT_MAX && tmp3 == INT_MAX){
              isok = 0;
              break;
            }
            tmp1 -= no1;
            if(chk1==0) tmp1+=30;
            tmp2 -= no2;
            if(chk2==0) tmp2+=30;
            tmp3 -= no3;
            if(chk3==0) tmp3+=30;
            if(tmp1<=0) continue;
            if(tmp2<=0) continue;
            if(tmp3<=0) continue;
            if(tmp1 <= tmp2 && tmp1 <= tmp2){
              no1 += no1+tmp1;
              if(chk1 == 0) no1 -= 30;
              chk1 = 1;
            }
            else if(tmp2 <= tmp1 && tmp2 <= tmp3){
              no2 += no2+tmp2;
              if(chk2 == 0) no2 -= 30;
              chk2 = 1;
            }
            else{
              no3 += no3+tmp3;
              if(chk3 == 0) no3 -= 30;
              chk3 = 1;
            }
          }
          if(!isok) continue;
          ans = no1+no2+no3;
          answer = min(answer ,ans+30*chk1+30*chk2+30*chk3);
        }
      }
    }

  }
  cout << answer << "\n";
  
  return 0;
}