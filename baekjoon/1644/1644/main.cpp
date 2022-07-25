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
ll sieve[4004000], left_pointer, right_poiner, psum, answer;
vector<ll> primes;

void calculate_primes() {
  for(ll i = 2; i <= 4000000; i++) {
    if(sieve[i] == 0) {
      primes.push_back(i);
      for(ll j = 1; i * j <= 4000000; j++) {
        sieve[i*j] = 1;
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  calculate_primes();
  cin >> n;
  left_pointer = 0;
  right_poiner = 0;
  psum = primes[0];
  while(true) {
    if(psum == n) {
      answer++;
    }
    if(psum < n) {
      if(right_poiner == primes.size() - 1) break;
      psum += primes[++right_poiner];
    } else {
      psum -= primes[left_pointer++];
    }
  }
  cout << answer << '\n';
  
  
  return 0;
}

