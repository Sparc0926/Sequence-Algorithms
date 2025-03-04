#ifndef SEQUENCE_H
#define SEQUENCE_H

typedef struct Sequence Seq;

struct Sequence {
    int* data;
    int len;
};

// returns the first-char index where subStr is exactly in str
// returns -1 if subStr is not in str
int IsExactlyIn(Seq* seq, Seq* subSeq);
//int IsIn(String* str, String* subStr);

// make subSeq into the longest increasing subsequence of seq
// if there are multiple, subSeq will be the one with least index
void LongestIncreasingSubsequence(Seq* seq, Seq* subSeq);

void test(void);

#endif//SEQUENCE_H