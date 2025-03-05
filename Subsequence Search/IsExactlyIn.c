#include <Sequence.h>
#include <stdio.h>

static void get_border_array(String* str, int* borderArr)
{
    borderArr[0] = 0;  // always 0
    for (int i = 1; i < str->len; i++) {
        // initialize with 0 or 1
        borderArr[i] = (str->data[0] == str->data[i]);
        // iterate through the longest length of subborders
        for (int j = borderArr[i - 1]; j > 0; j = borderArr[j - 1]) {
            if (str->data[i] == str->data[j]) {
                borderArr[i] = j + 1;
                break;
            }
        }
    }
}

#ifdef NAIVE  // O(mn)
int is_exactly_in(String* str, String* subStr)
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
int is_exactly_in(String* str, String* subStr)
{
    return -1;
}
#endif//BORDER_ARRAY



#ifdef RABIN_KARP
int is_exactly_in(String* str, String* subStr)
{
    return -1;
}
#endif//RABIN_KARP



#ifdef BOYER_MOORE
int is_exactly_in(String* str, String* subStr)
{
    return -1;
}
#endif//BOYER_MOORE



#ifdef KMP
int is_exactly_in(String* str, String* subStr)
{
    return -1;
}
#endif//KMP



void test()
{
    String s = {"abacaba", 7};
    int borderArr[s.len];

    get_border_array(&s, borderArr);
    for (int i = 0; i < s.len; i++) {
        printf("%d ", borderArr[i]);
    }
    printf("\n");

    return;
}