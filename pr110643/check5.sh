#!/bin/sh -x
#g++ -o works inf2.ii -O0 -lhwy -lhwy_test -Wall -Wextra -Wno-narrowing -Wfatal-errors
g++ -g -o works inf5.cc -O0 /tmp/arr.cc -Wall -Wextra -Werror -Wfatal-errors 
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi

clang++-16 -g -o works0 inf5.cc /tmp/arr.cc  -Wall -Wextra -Werror -Wfatal-errors 
if ! test "$?" = "0"; then
  exit 1
fi

#valgrind --leak-check=yes --error-exitcode=1 ./works 
valgrind --error-exitcode=1 ./works 
if ! test "$?" = "0"; then
  exit 1
fi

#g++ -o fails inf2.ii -O1 -lhwy -lhwy_test -Wall -Wextra -Wno-narrowing -Wfatal-errors
g++ -g -o fails inf5.cc -O1  /tmp/arr.cc -Wall -Wextra -Werror -Wfatal-errors 
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi

./fails 2>&1 | grep --fixed-strings "NEON_WITHOUT_AES, f64x1 lane 0 mismatch: expected '-nan', got '0.000000000000000000'."
