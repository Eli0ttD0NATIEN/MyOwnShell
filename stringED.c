#include <stdlib.h>
#include <stdio.h>
#include "stringED.h";

void* memcpyED(void *dest,	const void *src, size_t size) {
	const unsigned char* srcC = (const unsigned char*)src;
	unsigned char* destC = (char unsigned*)dest;
	if (dest != src) {
		size_t i = 0;
		while (i < size) {
			destC[i] = srcC[i];
			i++;
		}
	}
	return dest;
}

void* memchrED(const void* memoryBlock, int searchedChar, size_t size) {
	char* memoryBlockC = (char*)memoryBlock;
	char* searchedCharC = (char*)searchedChar;
	for (size_t i = 0; i < size; i++) {
		if (memoryBlockC[i] == searchedCharC) {
			return memoryBlockC[i];
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
	if (dest != src) {
		while (size--) {
			*((unsigned char*)dest + size) = *((unsigned char*)src + size);
		}
	}
	return dest;
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
		for (size_t i = 0; i < sizeSrc; ++i) {
			*(strDest + i + sizeSrc) = strSrc[i];
		}
		return strDest;
	}
	return NULL;
}

char* strchrED(const char* str, int searchedChar) {
	while (*str != (char)searchedChar) {
		if (!*str++) return NULL;
	}
	return (char*)str;
}

size_t strlenED(const char* str) {
	size_t len = 0;
	while (*str++) {
		len++;
	}
	return len;
}

char* strtokED(char* strToken, const char* delimiters) {
	static char* tmpBuffer = NULL;
	static char* finalBuffer = NULL;
	int i;
	static BOULEAN endToken = false;
	if (delimiters == NULL) return NULL;
	if (endToken) return NULL;
	if (strToken != NULL) tmpBuffer = strToken;
	finalBuffer = tmpBuffer;
	for (i = 0; i <= strlenED(tmpBuffer); i++) {
		if (tmpBuffer[i] == '\0') {
			endToken = true;
			return finalBuffer;
		}
		if (isADelimiter(tmpBuffer + i, delimiters)) {
			tmpBuffer[i] = '\0';
			tmpBuffer += i+1;
			return finalBuffer;
		}
	}
	return NULL;
}

BOULEAN isADelimiter(char* c, const char* delimiters) {
	while (*delimiters) {
		if (*delimiters++ == *c) return true;
	}
	return false;
}