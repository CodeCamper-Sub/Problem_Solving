#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, d, k, c, answer, partial_answer;
vector<ll> cnt, arr;

void add(ll i) {
  if(cnt[i] == 0) {
    partial_answer += 1;
  }
  cnt[i]++;
}

void remove(ll i) {
  if(cnt[i] == 1) {
    partial_answer -= 1;
  }
  cnt[i]--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> d >> k >> c;

  cnt.assign(d + 1, 0);
  arr.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for(ll i = 0; i < k; i++) {
    add(arr[i]);
  }

  answer = partial_answer + (cnt[c] == 0 ? 1 : 0);
  for(ll i = 0; i < n; i++) {
    remove(arr[i]);
    add(arr[(i + k) % n]);
    answer = max(answer, partial_answer + (cnt[c] == 0 ? 1 : 0));
  }

  cout << answer << '\n';
  
  return 0;
}