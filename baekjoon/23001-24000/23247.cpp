#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int N, M;
int arr[310][310], sum[310][310];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + arr[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      for (int x = 0; x < 10 && i+x <=N; ++x) {
        for (int y = 0; y < 10 && j+y <=M; ++y) {
          int now = sum[i+x][j+y] - sum[i+x][j-1]  - sum[i-1][j+y] + sum[i-1][j-1];
          if(now ==10) {
            ans++;
          }
        }
      }
    }
  }

  cout<<ans;

  return 0;
}