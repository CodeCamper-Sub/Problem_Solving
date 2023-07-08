#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;
ll A, B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  ll tt = 0;
  A = -1;
  for(ll i = 1; i <= 3000 ; i++){
    string a = to_string(i);
    string tmp = "";
    ll t = tt;
    while(a.size() > tmp.size()){
      tmp += s[t];
      t++;
    }

    if(tmp == a){
      if(A == -1)A = stoi(tmp);
      tt = t;
      if(tt > s.size()-1){
        cout << A << " " << tmp << "\n";
        return 0;
      }
    }
    else{
      A = -1;
      tt = 0;
    }
  }
  
  
  return 0;
}