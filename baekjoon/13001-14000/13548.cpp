#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, sqrtN, cnt[100001], ccnt[100001], maximum;
vector<ll> A, answers;
vector<tuple<ll, ll, ll>> queries;

void add(ll s) {
  ccnt[cnt[s]]--;
  cnt[s]++;
  ccnt[cnt[s]]++;
  maximum = max(maximum, cnt[s]);
}

void erase(ll s) {
  ccnt[cnt[s]]--;
  cnt[s]--;
  ccnt[cnt[s]]++;
  while(maximum > 0 && ccnt[maximum] == 0) maximum--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  A.resize(N + 1);
  for (ll i = 1; i <= N; i++)
    cin >> A[i];
  cin >> M;
  answers.resize(M);
  queries.resize(M);
  for (ll i = 0; i < M; i++) {
    cin >> get<0>(queries[i]) >> get<1>(queries[i]);
    get<2>(queries[i]) = i;
  }
  sqrtN = sqrt(N);
  sort(queries.begin(), queries.end(), [](auto a, auto b) {
    return get<0>(a) / sqrtN != get<0>(b) / sqrtN
               ? get<0>(a) / sqrtN < get<0>(b) / sqrtN
               : get<1>(a) < get<1>(b);
  });
  ll s = INF, e = INF;
  for(auto [ns, ne, index]: queries) {
    if(s == INF) {
      for(ll i = ns; i <= ne; i++) {
        add(A[i]);
      }
      s = ns;
      e = ne;
    } else {
      while(e < ne) {
        e++;
        add(A[e]);
      }
      while(ne < e) {
        erase(A[e]);
        e--;
      }
      while(s < ns) {
        erase(A[s]);
        s++;
      }
      while(ns < s) {
        s--;
        add(A[s]);
      }
    }
    answers[index] = maximum;
  }

  for(ll answer: answers) {
    cout << answer << '\n';
  }

  return 0;
}