#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int N, M, K;

vector<int> treasure[100010];
map<int, int> endPoint;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < K; ++i) {
    int X, Y;
    cin >> X >> Y;
    treasure[X].push_back(Y);
  }
  for (int i = 1; i <= N; ++i) {
    if (treasure[i].empty())
      continue;

    sort(treasure[i].begin(), treasure[i].end());
  }
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (treasure[i].empty())
      continue;
    if (endPoint.empty()) {
      endPoint[treasure[i].back()]++;
      continue;
    }
    auto iter = endPoint.upper_bound(treasure[i][0]);

    if (iter == endPoint.begin()) {
      int idx = lower_bound(treasure[i].begin(), treasure[i].end(), iter->first) -
                treasure[i].begin();
      if (idx == (int)treasure[i].size()) {
        endPoint[treasure[i].back()]++;
        continue;
      }
      endPoint[treasure[i][idx - 1]]++;
      iter->second--;
      endPoint[treasure[i].back()]++;
      continue;
    }

    --iter;
    iter->second--;
    endPoint[treasure[i].back()]++;
  }

  for (auto iter = endPoint.begin(); iter != endPoint.end(); ++iter) {
    ans += iter->second;
  }

  cout << ans;

  return 0;
}