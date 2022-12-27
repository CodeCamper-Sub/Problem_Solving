#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N;
string S;
set<char> first = {'H', 'D', 'C', 'S'};
set<char> second = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
set<string> cards;

bool contains(set<char> s, char c) {
  if(s.find(c) != s.end()) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  bool answer = true;
  for(ll i = 0; i < N; i++) {
    cin >> S;
    if(S.size() == 2 && contains(first, S[0]) && contains(second, S[1]) && cards.find(S) == cards.end()) {
      cards.insert(S);
    } else {
      answer = false;
    }
  }

  if(answer) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}