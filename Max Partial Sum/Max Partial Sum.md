# Max Partial Sum

This problem asks us to find the max sum of consecutive subsequences of a given sequence. To solve it, we iterate through $seq$ with maintainance of two attributes

1. $max$, records the current **max partial sum**;
2. $sum[n]$, $sum[i]$ is the **max tail sum** of $seq[0:i]$.

>***Lemma.*** At each iterarion, $sum[i]=\textup{max}(seq[i],seq[i]+sum[i-1])$.
>**proof.** Since $sum[i]$ involves $seq[i]$, it either or not involves $seq[i-1]$.
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; If it involves $seq[i-1]$, it's added upon a tail sum of $seq[i-1]$, hence $seq[i]+sum[i-1]$ is maximal.\
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; If it does not involves $seq[i-1]$, it can only be $seq[i]$ itself.

One might also notice that to evaluate `max(seq[i], seq[i] + sum[i - 1])` is the same as evaluating `max(0, sum[i - 1])` which can be simply written as

```c
sum[i] = sum[i - 1] < 0 ? seq.data[i] : seq.data[i] + sum[i - 1];
```

It can be also noticed that the only possibility to update $max$ is when $sum[i]>max$, hence

```c
if (sum[i] > max)  max = sum[i];
```

The complete code is

```c
int sum[0] = seq->data[0], max = sum[0];
for (int i = 1; i < seq->len; i++) {
    sum[i] = sum[i - 1] < 0 ? seq->data[i] : seq->data[i] + sum[i - 1];
    if (sum[i] > max)  max = sum[i];
}
return max;
```

While $sum$ can be a single variable as

```c
int sum = seq->data[0], max = sum;
for (int i = 1; i < seq->len; i++) {
    sum = sum < 0 ? seq->data[i] : seq->data[i] + sum;
    if (sum > max)  max = sum;
}
return max;
```
