//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n, k, q, a, l;
vector<ll> pieces;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k >> q;
  for(int i = 1; i <= k; i++) {
    cin >> a;
    pieces.push_back(a);
  }
  for(ll i = 1; i <= q; i++) {
    cin >> l;
    ll index = l-1;
    if(pieces[index] == n) {
      continue;
    }
    if(index == pieces.size() - 1 || pieces[index] + 1 != pieces[index+1]) {
      pieces[index] += 1;
    }
  }
  
  for(ll i = 0; i < pieces.size(); i++) {
    cout << pieces[i] << ' ';
  }
  
  return 0;
}

