#!/usr/bin/python/python2.4

def fibonacci(n, cache):
    if not n in cache:
        cache[n] = fibonacci(n - 1, cache) + fibonacci(n - 2, cache)

    return cache[n]

if __name__ == '__main__':
    term = 0;
    cache = {0:0, 1:1}
    
    while len(str(fibonacci(term, cache))) < 1000:
        term = term + 1

    print term
