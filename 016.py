#!/usr/bin/python/python2.4

def digit_sum(number):
    return reduce(lambda x, y: int(x) + int(y), str(number))

if __name__ == '__main__':
    print digit_sum(2 ** 1000)
