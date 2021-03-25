int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new) {
int *p = NULL;
int n = 0;
if (n_new > 0) p = new int[n_new];
if (source != NULL) {
    if (n_old > n_new) n = n_new;
    else n = n_old;
    for (int i = 0; i < n;i++) p[i]=source[i];
    delete[] source;
}
return p;
}
