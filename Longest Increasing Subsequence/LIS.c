#include <Sequence.h>
#include <stdio.h>

#ifdef NAIVE  // O(n^2)
void LongestIncreasingSubsequence(Seq* seq, Seq* subSeq)
{
    int length[seq->len];
    for (int i = 0; i < seq->len; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) {
            if (length[i] <= length[j] && seq.data[i] > seq.data[j])
                length[i] = length[j] + 1;
        }
    }
}
#endif//NAIVE

#ifdef BINARY_SEARCH  // O(nlogn)
void LongestIncreasingSubsequence(Seq* seq, Seq* subSeq)
{
    int length[seq->len];
    for (int i = 0; i < seq->len; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) {
            if (length[i] <= length[j] && seq.data[i] > seq.data[j])
                length[i] = length[j] + 1;
        }
    }
}
#endif//BINARY_SEARCH