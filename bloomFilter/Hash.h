#ifndef _HASH_H_
#define _HASH_H_
#define K 11 //¹şÏ£º¯Êı¸öÊı
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
	unsigned int(*hashFamily[K])(char *str, unsigned int len) =
	{ Hash::RSHash,Hash::JSHash,Hash::PJWHash,Hash::ELFHash,
	Hash::BKDRHash,Hash::SDBMHash,Hash::DJBHash,Hash::DEKHash,
	Hash::BPHash,Hash::FNVHash,Hash::APHash };
};
#endif