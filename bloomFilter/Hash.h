#ifndef _HASH_H_
#define _HASH_H_
#define K 11 //¹þÏ£º¯Êý¸öÊý
class Hash {
public:
	static unsigned int RSHash(char* str, unsigned int len);
	static unsigned int JSHash(char* str, unsigned int len);
 	static unsigned int PJWHash(char* str, unsigned int len);
	static unsigned int ELFHash(char* str, unsigned int len);
	static unsigned int BKDRHash(char* str, unsigned int len);
	static unsigned int SDBMHash(char* str, unsigned int len);
	static unsigned int DJBHash(char* str, unsigned int len);
	static unsigned int DEKHash(char* str, unsigned int len);
	static unsigned int BPHash(char* str, unsigned int len);
	static unsigned int FNVHash(char* str, unsigned int len);
	static unsigned int APHash(char* str, unsigned int len);
	unsigned int(*hashFamily[K])(char *str, unsigned int len);
	Hash() {
		hashFamily[0] = Hash::RSHash;
		hashFamily[1] = Hash::JSHash;
		hashFamily[2] = Hash::PJWHash;
		hashFamily[3] = Hash::ELFHash;
		hashFamily[4] = Hash::BKDRHash;
		hashFamily[5] = Hash::SDBMHash;
		hashFamily[6] = Hash::DJBHash;
		hashFamily[7] = Hash::DEKHash;
		hashFamily[8] = Hash::BPHash;
		hashFamily[9] = Hash::FNVHash;
		hashFamily[10] = Hash::APHash;
	}
};
#endif