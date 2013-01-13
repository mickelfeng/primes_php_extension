#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "primes.h"

zend_function_entry primes_functions[] = {
    PHP_FE(is_prime, NULL)
    PHP_FE(next_prime, NULL)
    PHP_FE(get_num_divisors, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry primes_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_PRIMES_EXTNAME,
    primes_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_PRIMES_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PRIMES
ZEND_GET_MODULE(primes)
#endif

PHP_FUNCTION(is_prime)
{
    long int n;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &n) ==
            FAILURE) {
        RETURN_NULL();
    }

    int v = is_prime(n);
    if(v) {
        RETURN_TRUE;
    }
    else {
        RETURN_FALSE;
    }
}

PHP_FUNCTION(next_prime)
{
    long int n;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &n) == 
            FAILURE) {
        RETURN_NULL();
    }

    long int next = next_prime(n);

    RETURN_LONG(next);
}

PHP_FUNCTION(get_num_divisors)
{
    long int n;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &n) ==
            FAILURE) {
        RETURN_NULL();
    }

    if(1 == n){
        RETURN_LONG(1);
    }

    // Fill primes table
    int primes[65500];
    fill_primes_table(primes, 65500);

    // Find the number of divisors
    int i, exponent, n_divisors = 2;
    for(i = 0; i < 65500; i++) {
        if(primes[i]*primes[i] > n) {
            break;
        }

        exponent = 1;

        while(n % primes[i] == 0) {
            n = n / primes[i];
            exponent++;
        }

        if(1 == n){
            RETURN_LONG(n_divisors);
        }

        n_divisors = n_divisors*exponent;
    }

    RETURN_LONG(n_divisors);
}
