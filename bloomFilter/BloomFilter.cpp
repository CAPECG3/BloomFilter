#include"BloomFilter.h"
#include"Hash.h"
#include<cmath>
#include<iostream>
#include<cstring>
void BloomFilter::bfAdd(unsigned int(*hashFamily[])(char *str, unsigned int len), char *x) {
	for (int i = 0; i < K; i++) {
		int len = strlen(x);
		unsigned int hash=(*hashFamily[i])(x, len);
		unsigned int index = hash%m;
		binary[index] = true;
	}
}
bool BloomFilter::bfSearch(unsigned int(*hashFamily[])(char *str, unsigned int len), char *x)
 {
	for (int i = 0; i < K; i++) {
		int len = strlen(x);
		unsigned int hash=(*hashFamily[i])(x, len);
		unsigned int index = hash%m;
		if (binary[index] == false) {
			return false;
		}
	}
	return true;
}
void BloomFilter::bfCheck(ifstream &fpStrPool, ifstream &fpCheckedStr, ofstream &fpResult) {
	char s[320];
	Hash h;
	while (fpStrPool >> s) {
		bfAdd(h.hashFamily, s);
	}
	int yesCount = 0; //统计yes的个数
	while (fpCheckedStr >> s) {
		if (!bfSearch(h.hashFamily, s)) {
			fpResult << "no" << endl;
		}
		else {
			yesCount++;
			fpResult << "yes" << endl;
		}
	}
	fpResult << "nums of 'yes':" << yesCount << endl;
}