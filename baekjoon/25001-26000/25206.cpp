#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string name, grade;
double num, sum, total;

double grade_to_score(string grade) {
  if(grade == "A+") {
    return 4.5;
  } else if(grade == "A0") {
    return 4.0;
  } else if(grade == "B+") {
    return 3.5;
  } else if(grade == "B0") {
    return 3.0;
  } else if(grade == "C+") {
    return 2.5;
  } else if(grade == "C0") {
    return 2.0;
  } else if(grade == "D+") {
    return 1.5;
  } else if(grade == "D0") {
    return 1.0;
  } else {
    return 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed;
  cout.precision(6);

  for(ll tt = 0; tt < 20; tt++) {
    cin >> name >> num >> grade;
    if(grade != "P") {
      total += num * grade_to_score(grade);
      sum += num;
    }
  }

  cout << total / sum << '\n';

  return 0;
}