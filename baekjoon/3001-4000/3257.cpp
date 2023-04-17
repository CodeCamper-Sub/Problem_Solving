#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string c, k, a;
vector<ll> answer;
bool memo[160][160][310];

bool backtracking(ll ic, ll ik, ll ia) {
  if(memo[ic][ik][ia]) return false;
  memo[ic][ik][ia] = true;
  if(ia == a.size()) return true;
  if(ic < c.size() && c[ic] == a[ia]) {
    answer.push_back(1);
    if(backtracking(ic + 1, ik, ia + 1)) {
      return true;
    }
    answer.pop_back();
  }
  if(ik < k.size() && k[ik] == a[ia]) {
    answer.push_back(2);
    if(backtracking(ic, ik + 1, ia + 1)) {
      return true;
    }
    answer.pop_back();
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> c >> k >> a;
  backtracking(0, 0, 0);

  for(ll a: answer) {
    cout << a;
  }
  
  return 0;
}