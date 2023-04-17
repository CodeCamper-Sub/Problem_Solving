#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, sum;
vector<ll> arr;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  arr.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll g = arr[1] - arr[0];
  for(ll i = 1; i < n; i++) {
    g = gcd(g, arr[i] - arr[i - 1]);
    sum += arr[i] - arr[i-1];
  }

  cout << sum / g + 1 - n << '\n';
  
  return 0;
}