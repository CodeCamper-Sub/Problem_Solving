#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll N, K, D, M, l, r, e, answer;
vector<vector<ll>> A;
vector<pair<ll, ll>> d;
vector<ll> cnt;

void add() {
  ll student_id = d[++r].second;
  ll e = 0;
  for(ll i = 0; i < K; i++) {
    cnt[i] += A[student_id][i];
    if(cnt[i] > 0 && cnt[i] < r - l + 1) {
      e += r - l + 1;
    }
  }
  answer = max(answer, e);
}

void remove() {
  ll student_id = d[l++].second;
  for(ll i = 0; i < K; i++) {
    cnt[i] -= A[student_id][i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> K >> D;
  A.assign(N, vector<ll>(K, 0));
  d.resize(N);
  for(ll i = 0; i < N; i++) {
    cin >> M >> d[i].first;
    d[i].second = i;
    while(M--) {
      ll a;
      cin >> a;
      A[i][--a] = 1;
    }
  }

  sort(d.begin(), d.end());
  cnt.assign(K, 0);

  ll student_id = d[0].second;
  for(ll i = 0; i < K; i++) {
    cnt[i] += A[student_id][i];
  }

  while(r < N - 1) {
    while(r < N - 1 && d[r + 1].first - d[l].first <= D) {
      add();
    }
    while(r < N - 1 && d[r + 1].first - d[l].first > D) {
      remove();
    }
  }

  cout << answer << '\n';
  
  return 0;
}