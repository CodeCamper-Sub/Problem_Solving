#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true) {
    cin >> n;
    if(n == -1) break;
    vector<ll> dividers;
    ll sum = 0;
    for(ll i = 1; i < n; i++) {
      if(n % i == 0) {
        dividers.push_back(i);
        sum += i;
      }
    }
    if(n != sum) {
      cout << n << " is NOT perfect.\n";
    } else {
      cout << n << " = ";
      for(ll i = 0; i < dividers.size() - 1; i++) {
        cout << dividers[i] << " + ";
      }
      cout << dividers.back() << '\n';
    }
  }

  return 0;
}