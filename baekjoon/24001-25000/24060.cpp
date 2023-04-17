#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, cnt;
ll arr[500500], tmp[500500];;

void merge(ll a[], ll p, ll q, ll r) {
  ll i = p;
  ll j = q + 1;
  ll t = 1;
  while(i <= q && j <= r) {
    if (a[i] <= a[j]) {
      tmp[t++] = a[i++];
    } else {
      tmp[t++] = a[j++];
    }
  }
  while(i <= q) {
    tmp[t++] = a[i++];
  }
  while(j <= r) {
    tmp[t++] = a[j++];
  }
  i = p;
  t = 1;
  while(i <= r) {
    cnt++;
    if(cnt == k) {
      cout << tmp[t];
    }
    a[i++] = tmp[t++];
  }
}

void merge_sort(ll a[], ll p, ll r) {
  if(p < r) {
    ll q = (p+r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q+1, r);
    merge(a, p, q, r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  merge_sort(arr, 0, n-1);
  if(cnt < k) {
    cout << -1 << '\n';
  }
  return 0;
}