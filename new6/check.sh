#!/bin/sh
set -x
input=math_test.cc
#g++ -std=c++14 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -g -m32 -fexcess-precision=standard -O2 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
g++ -std=c++11 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -g -m32 -fexcess-precision=fast -O1 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
./works > /tmp/works.txt 2>&1
cmp /tmp/works.txt /home/mathieu/Perso/gcc-110622/new6/works.txt
if ! test "$?" = "0"; then
  exit 1
fi

g++ -std=c++11 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -g -m32 -fexcess-precision=fast -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails  )
if ! test "$?" = "0"; then
  exit 1
fi
./fails > /tmp/fails.txt 2>&1
cmp /tmp/fails.txt /home/mathieu/Perso/gcc-110622/new6/fails.txt
if ! test "$?" = "0"; then
  exit 1
fi
