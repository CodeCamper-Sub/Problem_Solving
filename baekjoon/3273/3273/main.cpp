//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, arr[100100], x;
ll used[2002000], answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> arr[i];
    used[arr[i]]++;
  }
  
  cin >> x;
  for(ll i = 1; i <= n; i++) {
    if(x - arr[i] > 0) {
      if(used[x - arr[i]]){
        answer++;
      }
    }
  }
  cout << answer / 2 << '\n';
  return 0;
}

