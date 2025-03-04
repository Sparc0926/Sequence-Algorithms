#include <stdio.h>
#include <time.h>
#include <Sequence.h>

int main()
{
    time_t begin = time(NULL);

    test();

    time_t end = time(NULL);
    printf("It takes %lf seconds\n", difftime(end, begin));
    
    return 0;
}