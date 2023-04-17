#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, recursion_count;
string s;

int recursion(string *s, int l, int r) {
  recursion_count++;
  if(l >= r) return 1;
  else if((*s)[l] != (*s)[r]) return 0;
  else return recursion(s, l+1, r-1);
}

int isPalindrome(string *s) {
  return recursion(s, 0, (*s).length()-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  while(n--) { 
    recursion_count = 0;
    cin >> s;
    cout << isPalindrome(&s) << ' ' << recursion_count << '\n';
  }

  return 0;
}