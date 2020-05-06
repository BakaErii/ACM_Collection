/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-30 23:03:27
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
  double l,h;
  scanf("%lf %lf",&h,&l);
  printf("%.8f\n",l*l/(double)2/h-h/(double)2);
	return 0;
}