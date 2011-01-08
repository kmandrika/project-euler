#!/usr/bin/python/python2.4

def digit_sum(number):
    return reduce(lambda x, y: int(x) + int(y), str(number))

if __name__ == '__main__':
    factorial = lambda n, acc = 1: n and factorial(n - 1, acc * n) or acc
    print digit_sum(factorial(100))
