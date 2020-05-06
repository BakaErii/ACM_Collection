/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-13 19:16:10
 *
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;


const string strfind = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string strp = "A...3..HIL.JM.O...2TUVWXY5O1SE.Z..8.";

int main(void) {
	int i, j, isPalindrome, isMorrored;
	string str;
	while (getline(cin, str)) {
		isPalindrome = 1;
		isMorrored = 1;
		for (i = 0; i != (int)str.length() / 2 + 1; i++) {
			for (j = 0; j != (int)strfind.length(); j++) {
				if (str[i] == strfind[j]) {
					//判断回文串
					if (str[str.length() - i - 1] != str[i] )
						isPalindrome = 0;
					//判断镜像串
					if (str[str.length() - i - 1] != strp[j])
						isMorrored = 0;
				}
			}
			if (isMorrored == 0 && isPalindrome == 0)
				break;
		}
		if (isMorrored == 0 && isPalindrome == 0)
			cout << str << " -- is not a palindrome." << endl << endl;
		else if (isMorrored == 0 && isPalindrome == 1)
			cout << str << " -- is a regular palindrome." << endl << endl;
		else if (isMorrored == 1 && isPalindrome == 0)
			cout << str << " -- is a mirrored string." << endl << endl;
		else
			cout << str << " -- is a mirrored palindrome." << endl << endl;
	}
	return 0;
}