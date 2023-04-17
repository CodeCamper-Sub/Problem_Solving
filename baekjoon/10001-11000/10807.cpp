#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, v, answer;
ll arr[110];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> v;
  for(ll i = 0; i < n; i++) {
    if(arr[i] == v) answer++;
  }
  cout << answer;

  return 0;
}