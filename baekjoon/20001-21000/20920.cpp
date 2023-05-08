#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
map<string, ll> cnt;
vector<string> memo;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  while (n--) {
    cin >> s;
    if (s.size() >= m) {
      cnt[s]++;
      if (cnt[s] == 1) {
        memo.push_back(s);
      }
    }
  }

  sort(memo.begin(), memo.end(), [](string a, string b) {
    if (cnt[a] != cnt[b])
      return cnt[a] > cnt[b];
    else if (a.size() != b.size())
      return a.size() > b.size();
    else
      return a < b;
  });

  for (string s : memo) {
    cout << s << '\n';
  }

  return 0;
}