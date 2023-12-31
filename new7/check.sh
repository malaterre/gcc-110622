#!/bin/sh
set -x
input=math_test.cc
g++ -std=c++11 -g -m32 -fexcess-precision=fast -O1 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works > /dev/null 2>&1 )
if ! test "$?" = "0"; then
  exit 1
fi
./works > /dev/null 2>/tmp/works.txt 
cmp /tmp/works.txt /home/mathieu/Perso/gcc-110622/new7/works.txt
if ! test "$?" = "0"; then
  exit 1
fi

clang++-16 -std=c++11 -fsanitize=memory -o works0 $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works0 )
if ! test "$?" = "0"; then
  exit 1
fi

g++ -std=c++11 -g -m32 -fexcess-precision=fast -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails > /dev/null 2>&1 )
if ! test "$?" = "0"; then
  exit 1
fi
./fails > /dev/null 2>/tmp/fails.txt
cmp /tmp/fails.txt /home/mathieu/Perso/gcc-110622/new7/fails.txt
if ! test "$?" = "0"; then
  exit 1
fi

#  g++ -std=c++11 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -g -m32 -fexcess-precision=fast -O2 -o testcase.cc math_test.cc -Wfatal-errors -Wall -Wextra -Werror -Wpedantic -E -P
