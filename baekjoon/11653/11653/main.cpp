//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n;
bool visited[10001000];
vector<ll> prime;

void calc_prime() {
  for(ll i = 2; i <= 10000000; i++) {
    if(visited[i] == false) {
      prime.push_back(i);
    }
    for(ll j = 2; i * j <= 10000000; j++) {
      visited[i*j] = true;
    }
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  
  if (n == 1) {
    return 0;
  }
  
  calc_prime();
  
  for(ll i = 0; i < prime.size(); i++) {
    while(n % prime[i] == 0) {
      cout << prime[i] << '\n';
      n /= prime[i];
    }
    if(n == 1) {
      break;
    }
  }
  
  return 0;
}

