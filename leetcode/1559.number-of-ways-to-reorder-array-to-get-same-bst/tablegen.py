#!/usr/bin/env python
# -*- coding: utf-8 -*-

mod = int(1e9 + 7)

modInv = [1]
lim = 1000
for i in range(lim):
    inv = modInv[mod % (i+1)] * (mod - mod // (i+1)) % mod if i else 1
    modInv.append(inv)


def shortForm(n):
    s10 = str(n)
    s16 = hex(n)
    return s10 if len(s10) < len(s16) else s16


if __name__ == '__main__':
    start = 'const int inv[] = {';
    print(start, end='')

    n_char = len(start)
    for i, n in enumerate(modInv):
        s = shortForm(n) + (',' if i < lim else '')
        n_char += len(s)
        print(s, end='')
        if n_char > 120:
            print()
            n_char = 0
    print('};')
