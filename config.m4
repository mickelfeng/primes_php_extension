PHP_ARG_ENABLE(primes,
    whether to enable Primes support,
    [ --enable-primes Enable Primes support])

if test "$PHP_PRIMES" = "yes"; then
    AC_DEFINE(HAVE_PRIMES, 1, [Whether you have Primes])
    PHP_NEW_EXTENSION(primes, primes.c primes_util.c, $ext_shared)
fi
