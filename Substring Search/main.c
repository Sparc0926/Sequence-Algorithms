#include <stdio.h>
#include <String.h>

int main()
{
    String s = {"Hello, World!", 13};
    String sub = {"World", 5};
    printf("%d\n", IsExactlyIn(&s, &sub));
    
    return 0;
}