#!/bin/sh -x
#gcc -o works $1 -O -Wfatal-errors
#g++-10 -std=c++11 -o works -DHWY_COMPILE_ONLY_EMU128 -DHWY_BROKEN_EMU128=0 -maltivec -mcpu=power8 -g -O3 widen_mul_test.cc -lhwy -lhwy_test -Wall -Wextra -Werror -Wfatal-errors
g++-11 -std=c++11 -o works -maltivec -mcpu=power8 -mstrict-align -g -O3 widen_mul_test.cc foo.cc -Wall -Wextra -Werror -Wfatal-errors
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi

valgrind --leak-check=yes --error-exitcode=1 ./works
if ! test "$?" = "0"; then
  exit 1
fi


#clang++-16 -std=c++14 -DHWY_COMPILE_ONLY_EMU128 -DHWY_BROKEN_EMU128=0 -O0 -o works0 widen_mul_test.cc -lhwy -lhwy_test -fsanitize=memory
#if ! test "$?" = "0"; then
#  exit 1
#fi
#( ulimit -t 10; ./works0 )
#if ! test "$?" = "0"; then
#  exit 1
#fi

#gcc -o fails $1 -O2 -Wfatal-errors
g++-12 -std=c++11 -o fails -maltivec -mcpu=power8 -mstrict-align -g -O3 widen_mul_test.cc foo.cc -Wall -Wextra -Werror -Wfatal-errors
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi
./fails 2>&1 | grep "EMU128, i16x8 lane 4 mismatch: expected '0x7FFF', got '0x0000'."
