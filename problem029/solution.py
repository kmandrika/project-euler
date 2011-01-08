#!/usr/bin/python/python2.4

def generate(min, max):
    return map(lambda a: map(lambda b: a ** b, range(min, max + 1)), range(min, max + 1))

if __name__ == '__main__':
    print len(set([item for sublist in generate(2, 100) for item in sublist]))
