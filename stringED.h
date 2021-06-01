typedef unsigned BOULEAN;
#define true 1
#define false 0
;
void* memcpyED(void* dest, const void* src, size_t size);
void* memchrED(const void* memoryBlock, int searchedChar, size_t size);
int memcmpED(const void* pointer1, const void* pointer2, size_t size);
void* memmoveED(void* dest, const void* src, size_t size);
void* memsetED(void* dest, int c, size_t count);
char* strcatED(char* strDest, const char* strSrc);
char* strtokED(char* strToken, const char* delimiters);
char * strchrED( const char * string, int searchedChar);
BOULEAN isADelimiter(char* c, const char* delimiters);
size_t strlenED(const char* str);