#!/usr/bin/python/python2.4

def sum(number):
    return reduce(lambda acc, x: acc + x ** x, list(range(1, number + 1)))

if __name__ == '__main__':
    print str(sum(1000))[-10:]
