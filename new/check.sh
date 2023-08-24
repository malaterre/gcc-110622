#!/bin/sh
input=testcase.i
g++-13 -o works $input -O -Wfatal-errors -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
g++-13 -o fails $input -O2 -Wfatal-errors -lhwy
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi
exit 0
