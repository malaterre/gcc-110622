#!/bin/sh
#set -x
input=t6.cxx
#g++-13 -o works $input -O -Wfatal-errors -Werror=return-type -Werror=write-strings -Werror=uninitialized -lhwy
#g++-13 -std=c++14 -o works $input -Og -Wfatal-errors -Wall -Werror -lhwy
g++-13 -std=c++14 -o works $input -Wfatal-errors -Wall -Werror -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
g++-13 -std=c++14 -o fails $input -O2 -Wfatal-errors -Wall -Wextra -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if ! test "$?" = "42"; then
  exit 1
fi
exit 0
