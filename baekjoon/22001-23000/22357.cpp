#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

int K, N;
vector<int> prime;

void init(){
  vector<bool> ch(3005, false);
  for(int i = 2; i <=3000; ++i){
    if(ch[i]) continue;
    for(int j = i+i; j<=3000;j += i){
      ch[j] = true;
    }
    if(i>2000) prime.push_back(i);
  }
}

void input(){
  cin>>K>>N;
}

void sol(){
  for(int i = 0 ;i <K;++i){
    int now = 1;
    for(int j = 0 ; j<N;++j){
      cout<<now<<" ";
      now+= prime[i];
    }
    cout<<"\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  input(); 
  sol();

  
  return 0;
}