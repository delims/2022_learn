long mult2(long,long);

void mulstore(long x,long y,long *dest) {
    long t = mult2(x,2);
    *dest = t;
}
