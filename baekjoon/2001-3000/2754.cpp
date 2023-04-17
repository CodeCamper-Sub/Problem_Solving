#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  double answer;
  if(s == "A+") {
    cout << "4.3";
  } else if(s == "A0") {
    cout << "4.0";
  } else if(s == "A-") {
    cout << "3.7";
  } else if(s == "B+") {
    cout << "3.3";
  } else if(s == "B0") {
    cout << "3.0";
  } else if(s == "B-") {
    cout << "2.7";
  } else if(s == "C+") {
    cout << "2.3";
  } else if(s == "C0") {
    cout << "2.0";
  } else if(s == "C-") {
    cout << "1.7";
  } else if(s == "D+") {
    cout << "1.3";
  } else if(s == "D0") {
    cout << "1.0";
  } else if(s== "D-") {
    cout << "0.7";
  } else {
    cout << "0.0";
  }
  
  return 0;
}