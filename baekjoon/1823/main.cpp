#include <iostream>
using namespace std;typedef int i;i n,v[2020],d[2020][2020];i f(i s, i e) {if(d[s][e])return d[s][e];if(s == e)return d[s][e]=v[s]*n;else return d[s][e]=max(f(s+1, e)+v[s]*(n-(e-s)),f(s,e-1)+v[e]*(n-(e-s)));}i main() {cin>>n;for(i i=0;i<n;i++)cin>>v[i];cout<<f(0,n-1);}