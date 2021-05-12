#include <stdlib.h>
#include <stdio.h>

void* memcpyED(void *dest,	const void *src, size_t size) {
	char *destC = (char*)dest;
	const char *srcC = (const char*)src;
	if (destC != NULL && srcC != NULL) {
		for (size_t i = 0; i <= size; i++) {
			destC[i] = srcC[i];
		}
	}
	return (char*)dest;
}

void* memchrED(const void* memoryBlock, int searchedChar, size_t size) {
	char* memoryBlockC = (char*)memoryBlock;
	char* searchedCharC = (char*)searchedChar;
	for (size_t i = 0; i <= size; i++) {
		if (memoryBlockC[i] == searchedCharC) {
			return (void*)memoryBlockC[i];
		}
	}
	return NULL;
}

int memcmpED(const void* buffer1, const void* buffer2, size_t size) {
	unsigned char* buffer1C = (unsigned char*)buffer1;
	unsigned char* buffer2C = (unsigned char*)buffer2;
	for (size_t i = 0; i < size; i++) {
		if (buffer1C[i] =! buffer2C[i]) {
			return buffer1C[i] - buffer2C[i];
		}
	}
	return 0;
}

void* memmoveED(void* dest, const void* src, size_t size) {
	char* tmpBuffer = malloc(size + 1);
	char* destC = (char*)dest;
	char* srcC = (char*)src;
	if(tmpBuffer != NULL){
		for (size_t i = 0; i < size; size++) {
			*(tmpBuffer + i) = *(srcC + i);
		}
		for (size_t i = 0; i < size; size++) {
			*(destC + i) = *(tmpBuffer + i);
		}
		free(tmpBuffer);
		return (char *)dest;
	}
	return NULL;
}

void* memsetED(void* dest, int c, size_t count) {
	char* destC = (char*)dest;
	while (count) {
		*(destC++) = c;
		count--;
	}
	return destC;
}
char* strcatED(char* strDest, const char* strSrc) {
	const size_t sizeSrc = sizeof(strSrc);
	const size_t size = sizeof(strDest) + sizeSrc;
	strDest = malloc(size + 1);
	if (strDest != NULL) {
		for (size_t i = 0; i < sizeSrc; i++) {
			*(strDest + i + sizeSrc) = strSrc[i];
		}
		return strDest;
	}
	return NULL;
}