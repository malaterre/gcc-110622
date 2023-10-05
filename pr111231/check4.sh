#!/bin/sh -x
g++ -std=c++11 -o works -O2 -g -Wfatal-errors -Werror -Wall -Wextra -Wconversion -DNDEBUG -march=armv7-a -mfpu=neon-vfpv4 -mfloat-abi=hard -mfp16-format=ieee -Wno-psabi widen_mul_test.cc /tmp/foo.cc
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

#clang++-16 -std=c++17 -Wfatal-errors -Werror -Wall -Wextra -DHWY_COMPILE_ONLY_EMU128 -DHWY_BROKEN_EMU128=0 -O2 -o works0 widen_mul_test.cc -lhwy -lhwy_test
clang++-16 -std=c++11 -Wfatal-errors -Werror -Wall -Wextra  -O2 -o works0 widen_mul_test.cc /tmp/foo.cc
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works0 )
if ! test "$?" = "0"; then
  exit 1
fi

g++ -std=c++11 -o fails -O2 -g -Wfatal-errors -DNDEBUG -fno-exceptions -march=armv7-a -mfpu=neon-vfpv4 -mfloat-abi=hard -mfp16-format=ieee -Wno-psabi widen_mul_test.cc /tmp/foo.cc
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi
#exit 0
./fails 2>&1 | grep lane | grep mismatch
