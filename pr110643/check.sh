#!/bin/sh -x
g++ -o works inf2.ii -O0 -lhwy -lhwy_test -Wno-narrowing -Wfatal-errors
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi

#valgrind --leak-check=yes --error-exitcode=1 ./works 

g++ -o fails inf2.ii -O1 -lhwy -lhwy_test -Wno-narrowing -Wfatal-errors
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi

./fails 2>&1 | grep --fixed-strings "NEON_WITHOUT_AES, f64x1 lane 0 mismatch: expected '-nan', got '0.000000000000000000'."
