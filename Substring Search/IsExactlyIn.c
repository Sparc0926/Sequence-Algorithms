#include <String.h>

static String* getBorderArray(String* str, int* borderArr)
{
    borderArr[0] = 0;  // always 0
    for (int i = 1; i < str->len; i++) {
        int j = i;
        if (str->data[i] == str->data[borderArr[i - 1]])
        borderArr[i] = borderArr[i - 1]++;
    }
    //
    int i = 1, j = 0;
    borderArr[0] = 0;
    while (i < str->len) {
        if (str->data[i] == str->data[j]) {
            borderArr[i] = j + 1;
            i++;
            j++;
        }
        else {
            if (j == 0) {
                borderArr[i] = 0;
                i++;
            }
            else  j = borderArr[j - 1];
        }
    }
    return str;
}

#ifdef NAIVE  // O(mn)
int IsExactlyIn(String* str, String* subStr)
{
    for (int i = 0; i <= str->len - subStr->len; i++) {
        int j = 0;
        while (j < subStr->len && str->data[i + j] == subStr->data[j])
            j++;
        if (j == subStr->len)  return i;
    }
    return -1;
}
#endif//NAIVE



#ifdef BORDER_ARRAY
int IsExactlyIn(String* str, String* subStr)
{
    return -1;
}
#endif//BORDER_ARRAY



#ifdef RABIN_KARP
int IsExactlyIn(String* str, String* subStr)
{
    return -1;
}
#endif//RABIN_KARP



#ifdef BOYER_MOORE
int IsExactlyIn(String* str, String* subStr)
{
    return -1;
}
#endif//BOYER_MOORE



#ifdef KMP
int IsExactlyIn(String* str, String* subStr)
{
    return -1;
}
#endif//KMP