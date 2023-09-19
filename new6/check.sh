#!/bin/sh
set -x
START=0
STOP=9218868437227405311
input=math_test.cc
#g++ -std=c++14 -g -m32 -fexcess-precision=standard -O2 '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o works $input -Wfatal-errors -Wall -Wextra -Werror -lhwy 
#g++ -std=c++11 -g -m32 -fexcess-precision=standard -O2 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
g++ -std=c++14 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -g -m32 -fexcess-precision=standard -O2 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic -lhwy -lhwy_test
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works $START $STOP )
if ! test "$?" = "0"; then
  exit 1
fi
./works $START $STOP > /tmp/works.txt 2>&1
cmp /tmp/works.txt /home/mathieu/Perso/gcc-110622/new6/works.txt
if ! test "$?" = "0"; then
  exit 1
fi

#./works $START $STOP 2>&1 | grep --fixed-strings 'Log1p(9.8046570862201476e-17) expected 9.8046570862201476e-17 actual 9.8046570862201476e-17'
#if ! test "$?" = "0"; then
#  exit 1
#fi

# do not use O2 just in case
#clang++-16 -std=c++14 -fsanitize=memory '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o works $input -Wfatal-errors -Wall -Wextra -Werror -lhwy 
clang++-16 -std=c++14 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -fsanitize=memory -o works0 $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic -lhwy -lhwy_test 
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works0 $START $STOP )
if ! test "$?" = "0"; then
  exit 1
fi
#g++ -o fails $input -O2 -Wfatal-errors -Wall -Wextra -lhwy
#g++ -std=c++14 -fexcess-precision=fast -g -m32 -O2 '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o fails $input -Wfatal-errors -Wall -Wextra -Werror -lhwy 
#g++ -std=c++11 -fexcess-precision=fast -g -m32 -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
g++ -std=c++14 -DHWY_BROKEN_EMU128=0 -DHWY_COMPILE_ONLY_EMU128 -g -m32 -fexcess-precision=fast -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic -lhwy -lhwy_test
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails $START $STOP )
if ! test "$?" = "0"; then
  exit 1
fi
./fails $START $STOP > /tmp/fails.txt 2>&1
cmp /tmp/fails.txt /home/mathieu/Perso/gcc-110622/new6/fails.txt
if ! test "$?" = "0"; then
  exit 1
fi

#./fails $START $STOP 2>&1 | grep --fixed-strings 'Log1p(9.8046570862201476e-17) expected 9.8046570862201476e-17 actual 0 '
#exit 0

# gcc '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -E -P math_test.cc

