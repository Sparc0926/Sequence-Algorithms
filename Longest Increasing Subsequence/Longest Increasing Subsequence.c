#include <Sequence.h>
#include <stdio.h>

#define BINARY_SEARCH

#ifdef NAIVE  // O(n^2)
void longest_increasing_subsequence(Seq* seq, Seq* subSeq)
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

#ifdef LEAST_TAIL  // O(nlogn)
void longest_increasing_subsequence(Seq* seq, Seq* subSeq)
{
    int length[seq->len], least_tail[seq->len + 1], max_len = 1;
    for (int i = 0; i < seq->len; i++) {
        length[i] = 1, least_tail[i + 1] = 0x7fffffff;
        int l = 1, r = max_len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (least_tail[mid] < seq[i].data)  l = mid + 1;
            else  r = mid;
        }
        if (seq.data[i] < least_tail[l + 1])  least_tail[l + 1] = seq.data[i];
        if (max_len < length[i] = l + 1)  max_len = l + 1;
    }
}
#endif//LEAST_TAILJ