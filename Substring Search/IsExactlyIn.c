#include <String.h>

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