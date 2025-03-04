#ifndef STRING_H
#define STRING_H

typedef struct String String;

struct String {
    char* data;
    int len;
};

// returns the first-char index where subStr is exactly in str
// returns -1 if subStr is not in str
int IsExactlyIn(String* str, String* subStr);
//int IsIn(String* str, String* subStr);

void test(void);

#endif//STRING_H