#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  string answer = "No";
  while(n--) {
    cin >> s;
    if(s == "and" || s == "not" || s == "that" || s == "the" || s == "you") {
        answer = "Yes";
    }
  }

  cout << answer;
  
  return 0;
}