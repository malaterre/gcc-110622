#!/bin/sh
#set -x
input=math_test.cc
g++ -fexcess-precision=standard -O2 '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o works $input -Wfatal-errors -Wall -Wextra -Werror -lhwy -lgtest
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
#g++ -o fails $input -O2 -Wfatal-errors -Wall -Wextra -lhwy
g++ -O2 '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o fails $input -Wfatal-errors -Wall -Wextra -Werror -lhwy -lgtest
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi
exit 0
