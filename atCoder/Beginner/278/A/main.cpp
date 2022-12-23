#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N, K;
  cin >> N >> K;
  vector<ll> arr;
  for(ll i = 0; i < N; i++) {
    ll a;
    cin >> a;
    arr.push_back(a);
  }
  for(ll i = 0; i < K; i++) {
    arr.erase(arr.begin());
    arr.push_back(0);
  }
  for(ll i = 0; i <arr.size(); i++){ 
    cout << arr[i] << ' ';
  }

  return 0;
}