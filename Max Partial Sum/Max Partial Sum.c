#include <Sequence.h>

int max_partial_sum(Seq* seq)
{
    int sum = seq->data[0], max = sum;
    for (int i = 1; i < seq->len; i++) {
        sum = sum < 0 ? seq->data[i] : seq->data[i] + sum;
        if (sum > max)  max = sum;
    }
    return max;
}