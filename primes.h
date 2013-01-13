#ifndef PHP_PRIMES_H
#define PHP_PRIMES_H 1

#define PHP_PRIMES_VERSION "1.0"
#define PHP_PRIMES_EXTNAME "primes"

PHP_FUNCTION(is_prime);
PHP_FUNCTION(next_prime);
PHP_FUNCTION(get_num_divisors);

extern zend_module_entry primes_module_entry;
#define phpext_primes_ptr &primes_module_entry

#endif
