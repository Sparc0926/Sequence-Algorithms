# Subsequence Search

These prolems require searching for a substring `subStr` inside a string `str`. In the following statements, `n`, `m` stand for `str.len` and `subStr.len` respectively and `str[i:j]` means the sliced substring from `str[i]` to `str[j]`.

## Exact Search

>***Definition.*** A substring `subStr` is **exactly in** `str` if and only if chars in `subStr` occur consecutively in `str` and are in correct order.

>***Example.*** `"lord"` is in `"Hello, world!"` but **not exactly**, while `"ello"` is **exactly in** `"Hello, world!"`.

|Algorithm   |time    |space|
|------------|--------|-----|
|Naïve       |$O(mn)$ |$O$  |
|Border Array|$O(m+n)$|$O$  |
|KMP         |$O(m+n)$|$O$  |

### Naïve $O(mn)$

```c
for (int i = 0; i <= str->len - subStr->len; i++) {
    int j = 0;
    while (j < subStr->len && str->data[i + j] == subStr->data[j])
        j++;
    if (j == subStr->len)  return i;
}
return -1;
```

As we can see, $T(m,n)=mn-m^{2}+n+1\in O(mn)$

### Border Array

>***Definition.*** A **border** of `str` is a **proper** substring `b` which is both prefix and suffix of `str`.

>***Definition.*** A **border array** of string `str` is an array `int borderArr[n]` with `borderArr[i]`   storing the **longest border length** of `str[0 : i]`.

>***Example.*** `str="abacaba"`, then `borderArr[n] = [0,0,1,0,1,2,3]` because
> |Substring             |logest border|longest border length|
> |----------------------|-------------|:-------------------:|
> |`b[0 : 0] = "a"`      |`""`         |0                    |
> |`b[0 : 1] = "ab"`     |`""`         |0                    |
> |`b[0 : 2] = "aba"`    |`"a"`        |1                    |
> |`b[0 : 3] = "abac"`   |`""`         |0                    |
> |`b[0 : 4] = "abaca"`  |`"a"`        |1                    |
> |`b[0 : 5] = "abacab"` |`"ab"`       |2                    |
> |`b[0 : 6] = "abacaba"`|`"aba"`      |3                    |

Here introduces a DP algorithm to compute the border array of `str` which runs in $O(n)$ time.

>***Lemma.*** Let `b` be the **longest** border of `str[0 : i - 1]` satisfying `str[i] == str[b.len]`, then either `borderArr[i] == b.len + 1` or `borderArr[i] == 0`.

>*proof.* Assume such `b`, then `str[0 : i] == b + str[b.len] + s + b + str[b.len]`,
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;which shows that `b + str[b.len]` is a border of `str[0 : i]`.
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Since it can't be longer, `borderArr[i] == b.len + 1`.
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Assume there's no such `b`, then `borderArr[i] == 0`.

This motivates the idea of finding the **longest** such border of `str[0 : i - 1]` first.

>***Lemma.*** Let `b1, b2` be borders of `str[0 : i]`, if `b1.len < b2.len`, then `b1` is a border of `b2`.

>*proof.* Assume `str[0 : i] == b1 + x + s + y + b1 == b2 + s + b2`, then `b1 + x == y + b1`, which means `b2 == b1 + z + b1` where `x == z + b1` and `y == b1 + z`.

We can iteratively look at the longest subborder of the previous border until finding such one that `str[i] == str[b.len]`. This process is given by the following code.

```c
// iterate through the longest subborder
for (int j = borderArr[i - 1]; j > 0; j = borderArr[j]) {
    if (str->data[i] == str->data[j]) {
        borderArr[i] = j + 1;
        break;
    }
}
```
