#!/bin/sh
input=t8.cxx
#g++-13 -o works $input -O -Wfatal-errors -Werror=return-type -Werror=write-strings -Werror=uninitialized -lhwy
g++-13 -o works $input -Wfatal-errors -Wall -Werror -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
g++-13 -fexcess-precision=standard -o works $input -O2 -Wfatal-errors -Wall -Werror -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi

g++-13 -o fails $input -O2 -Wfatal-errors -Wall -Werror -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if ! test "$?" = "42"; then
  exit 1
fi
exit 0
