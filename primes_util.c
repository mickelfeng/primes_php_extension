#include "primes_util.h"

int is_prime(long int n)
{
    if(1 == 0)
        return 0;

    int i;
    long int sqroot = sqrt(n);
    for(i = 1; i <= sqroot; i++) {
        if((n % i == 0) && (i > 1))
            return 0;
    }

    return 1;
}

long int next_prime(long int n)
{
    int step = 2;
    if(n % 2 == 0)
        n++;
    else
        n += 2;

    while(!is_prime(n)) {
        n += step;
    }

    return n;
}

void fill_primes_table(int table[], int table_size)
{
    int i, _next_prime = 3;
    table[0] = 2;
    for(i = 1; i < table_size; i++) {
        table[i] = _next_prime;
        _next_prime = next_prime(_next_prime);
    }
}
