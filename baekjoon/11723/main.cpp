#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll M, S, x;
string command;

bool operator==(string a, string b) {
  return a.compare(b) == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> M;
  for(ll i = 0; i < M; i++) {
    cin >> command;
    if(command == "add") {
      cin >> x;
      if ((S >> (x-1)) % 2 == 0) {
        S += 1 << (x-1);
      }
    } else if (command == "remove") {
      cin >> x;
      if ((S >> (x-1)) % 2 == 1) {
        S -= 1 << (x-1);
      }
    } else if (command == "check") {
      cin >> x;
      cout << (S >> (x-1)) % 2 << '\n';
    } else if (command == "toggle") {
      cin >> x;
      if ((S >> (x-1)) % 2 == 0) {
        S += 1 << (x-1);
      } else {
        S -= 1 << (x-1);
      }
    } else if (command == "all") {
      S = (1 << 21) - 1;
    } else if (command == "empty") {
      S = 0;
    }
  }

  return 0;
}