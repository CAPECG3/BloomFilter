#ifndef _BLOOM_FILTER_H_
#define _BLOOM_FILTER_H_
#include<fstream>
using namespace std;
class BloomFilter {
public:
	void bfCheck(ifstream &fpStrPool, ifstream &fpCheckedStr, ofstream &fpResult);
	BloomFilter() {
		mCount();
		binary = new bool[m];
		fill(binary, binary + m, false);
	}
private:
	//const int n=20051052;//字符串个数
	const int n=6;//字符串个数
	int m;//二进制位长度
	const int K = 11;//哈希函数个数
	const double p = 0.01;//错误率
	bool *binary;
	void mCount() {
		m = n*1.44*log2(1.0 / p);
	}
	void bfAdd(unsigned int(*hashFamily[])(char *str, unsigned int len), char *x);
	bool bfSearch(unsigned int(*hashFamily[])(char *str, unsigned int len), char *x);
};
#endif