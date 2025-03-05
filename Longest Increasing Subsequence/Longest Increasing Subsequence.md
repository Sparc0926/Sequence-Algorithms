# Longest Increasing Subsequence

### Naive $\Theta(n^{2})$

```c
int length[seq->len];
for (int i = 0; i < seq->len; i++) {
    length[i] = 1;
    for (int j = 0; j < i; j++) {
        if (length[i] <= length[j] && seq.data[i] > seq.data[j])
            length[i] = length[j] + 1;
    }
}
```

Not hard to see, $\displaystyle T(n)=\sum_{i=1}^{n}1+(i-1)=\frac{n^{2}}{2}+\frac{n}{2}\in \Theta(n^{2})$. However this can be optimized into $O(nlogn)$ in several ways.

### Least Tail

This approach constructs `int least_tail[n]` with `least_tail[k]` storing the **least tail** (least last element) of currently found increasing subsequences of length `k`.

> ***Lemma.*** `least_tail[n]` is an **increasing** array.
> **proof.** Suppose $\exists 1\leq i\leq n$ that `least_tail[k] <= least_tail[k - 1]`,
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; then $\exists$`seq[j] < least_tail[k] <= least_tail[k - 1]`
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; where `seq[j]` is the tail of a examined length `k - 1` increasing subsequence.
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; $\therefore$ `seq[j] < least_tail[k - 1]`, violating the asumption.

This allow us to binary search on `least_tail[n]` that finds the right one, combained with the folowing greedy idea.

> ***Greedy Idea.*** `length[i] = k + 1` where `seq[i] > least_tail[k] && seq[i] <= least_tail[k + 1]`.

```c
```
