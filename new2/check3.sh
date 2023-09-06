#!/bin/sh
set -x
input=math_test.cc
#g++ -std=gnu++11 -g -m32 -fexcess-precision=standard -O2 -o works1 $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
g++ -std=c++11 -g -m32 -O2 -o works1 $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works1 )
if ! test "$?" = "0"; then
  exit 1
fi
# do not use O2 just in case
clang++-16 -std=c++11 -fsanitize=memory -o works0 $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works0 )
if ! test "$?" = "0"; then
  exit 1
fi
#g++ -o fails $input -O2 -Wfatal-errors -Wall -Wextra -lhwy
g++ -std=gnu++11 -g -m32 -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi
g++ -std=gnu++11 -DDOPRINT -g -m32 -O2 -o works2 $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works2 )
if ! test "$?" = "0"; then
  exit 1
fi
exit 0

# gcc '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -E -P math_test.cc

