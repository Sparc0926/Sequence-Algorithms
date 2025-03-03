# Substring Search

These prolems require searching for a substring `subStr` inside a string `str`. In the following statements, `n`, `m` stand for `str.len` and `subStr.len` respectively and `str[i:j]` means the sliced substring from `str[i]` to `str[j]`.

## Exact Search

***Definition.*** A substring `subStr` is **exactly in** `str` if and only if chars in `subStr` occur consecutively in `str` and are in correct order.

***Example.*** `"lord"` is in `"Hello, world!"` but **not exactly**, while `"ello"` is **exactly in** `"Hello, world!"`.

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

***Definition.*** Substring `b` is a **border** of `str` if and only if it satisfies both

1. `b.len <= str.len / 2`;
2. `b` is both prefix and suffix of `str`.

***Definition.*** A **border array** of string `str` is an array `int borderArr[n]` with `borderArr[i]`   storing the **longest border length** of `str[0 : i]`.

***Example.*** `str="abacaba"`, then `borderArr[n] = [0,0,1,0,1,2,3]` because

|Substring             |logest border|longest border length|
|----------------------|-------------|:-------------------:|
|`b[0 : 0] = "a"`      |`""`         |0                    |
|`b[0 : 1] = "ab"`     |`""`         |0                    |
|`b[0 : 2] = "aba"`    |`"a"`        |1                    |
|`b[0 : 3] = "abac"`   |`""`         |0                    |
|`b[0 : 4] = "abaca"`  |`"a"`        |1                    |
|`b[0 : 5] = "abacab"` |`"ab"`       |2                    |
|`b[0 : 6] = "abacaba"`|`"aba"`      |3                    |

***Lemma.*** Let `b[0], b[1], ... ,b[k]` be the list of all borders of `str`, then either `borderArr[i + 1] == b[j].len + 1` for some $1\leq j\leq k$ or `borderArr[i + 1] == 0`.
*proof.* Assume `b[j]` is the longest border satisfying `str[b[j].len] == str[i + 1]`, then `b[j] + str[b[j].len]` is the longest border of `str[0 : i + 1]`, hence `borderArr[i + 1] == b[j].len + 1`.\
If $\forall 1\leq j\leq k$ `str[b[j].len] != str[i + 1]`, assume $\exists$ border 

```c
```
