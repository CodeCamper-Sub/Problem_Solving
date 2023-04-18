#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, answer, l;
vector<ll> arr, last, dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  arr.resize(n);
  last.assign(100001, -1);
  l = -1;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
    l = max(l, last[arr[i]]);
    answer += i - l;
    last[arr[i]] = i;
  }

  cout << answer << '\n';

  return 0;
}