#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "stringED.h"

void testMemcpyED() {
	char src[20] = "How Are you ?"; //Source String
	char dst[20] = { 0 }; //dst buffer
	//copy source buffer int dst
	memcpyED(dst, src, sizeof(src));
	printf("dst = %s\n", dst);
}

void testMemchrED() {
	int  ch = 'r';
	char str[] = "lazy";
	char string[] = "The quick brown dog jumps over the lazy fox";
	char fmt1[] = "         1         2         3         4         5";
	char fmt2[] = "12345678901234567890123456789012345678901234567890";
	char* pdest;
	int result;
	printf("String to be searched:\n             %s\n", string);
	printf("             %s\n             %s\n\n", fmt1, fmt2);

	printf("Search char: %c\n", ch);
	pdest = memchr(string, ch, sizeof(string));
	result = (int)(pdest - string + 1);
	if (pdest != NULL)
		printf("Result:      %c found at position %d\n", ch, result);
	else
		printf("Result:      %c not found\n");
}

void compareED(const void* val1, const void* val2, size_t size) {
	int result = memcmpED(val1, val2, size);
	if (result < 0)
		printf("First is less than second.\n");
	else if (result == 0)
		printf("First is equal to second.\n");
	else
		printf("First is greater than second.\n");
}

void testMemcmpED() {
	char first[] = "1234";
	char second[] = "1234";
	int int_arr1[] = {1,2,5};
	int int_arr2[] = {1,2,3};
	compareED(first, second, 3);
	compareED(int_arr1, int_arr2, 3);
}

void testMemmoveED() {
	char str1[7] = "aabbcc";
	printf("The string: %s\n", str1);
	memcpyED(str1 + 2, str1, 4);
	printf("New string: %s\n", str1);
	strcpy_s(str1, sizeof(str1), "aabbcc");   // reset string
	printf("The string: %s\n", str1);
	memmoveED(str1 + 2, str1, 4);
	printf("New string: %s\n", str1);
}

void testMemsetED() {
	char buffer[] = "This is a test of the memset function";
	printf("Before: %s\n", buffer);
	memsetED(buffer, '*', 4);
	printf("After:  %s\n", buffer);
}

void testStrcatED() {
	char str1[4] = "Leo";
	char str2[7] = "Eliott";
	printf("%s + %s \n", str1, str2);
	strcatED(str2, str1);
	printf("%s", str2);
}

void testStrchrED() {
	char str1[5] = "aaaba";
	char char2Find = 'b';
	char* posOfChar = strchrED(str1, char2Find);
	int result = (int)(posOfChar - str1 + 1);
	if (posOfChar != NULL)
		printf_s("Result:   first %c found at position %d\n", char2Find, result);
	else
		printf_s("Result:   %c not found\n", char2Find);
}