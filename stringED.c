#include <stdlib.h>
#include <stdio.h>

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

char* strchrED(const char* string, int searchedChar) {
	for (size_t count = 0; count < sizeof(string); ++count) {
		if (string[count] == searchedChar) {
			return string + count;
		}
	}
	return NULL;
}