import os;
import sys;
import re;
import random;

def printTowers(A, B, C):
    print("src=%s" % (A))
    print("tmp=%s" % (B))
    print("dst=%s" % (C))

def initTowers(A, B, C):
    for i in range(0,int(sys.argv[1])):
        A.append(i+1);
        B.append(0);
        C.append(0);

def swap(src, dst, n):
    print("swap")
    dst.append(src.pop(0))
    dst.pop(0)
    src.insert(0,0); #syntax for inserting at index 0
    print("src=%s" % (src))
    print("dst=%s" % (dst))

def sortTowers(src, tmp, dst, n):
    if n == 0:
        return
    print("n=%s" % (n))
    sortTowers(src,dst,tmp,n-1)
    swap(src,dst,n)
    swap(tmp,dst,n)

def main():

    A = []
    B = []
    C = []

    initTowers(A, B, C)
    printTowers(A, B, C)
    sortTowers(A,B,C,len(A))
    printTowers(A, B, C)

main()
