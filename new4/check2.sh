#!/bin/sh
set -x
input=math_test.cc
#g++ -std=c++14 -g -m32 -fexcess-precision=standard -O2 '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o works $input -Wfatal-errors -Wall -Wextra -Werror -lhwy 
#g++ -std=c++11 -g -m32 -fexcess-precision=standard -O2 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
g++ -std=c++11 -g -m32 -fexcess-precision=standard -O2 -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic 
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
# do not use O2 just in case
#clang++-16 -std=c++14 -fsanitize=memory '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o works $input -Wfatal-errors -Wall -Wextra -Werror -lhwy 
clang++-16 -std=c++11 -fsanitize=memory -o works $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./works )
if ! test "$?" = "0"; then
  exit 1
fi
#g++ -o fails $input -O2 -Wfatal-errors -Wall -Wextra -lhwy
#g++ -std=c++14 -fexcess-precision=fast -g -m32 -O2 '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -o fails $input -Wfatal-errors -Wall -Wextra -Werror -lhwy 
#g++ -std=c++11 -fexcess-precision=fast -g -m32 -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
g++ -std=c++11 -g -m32 -fexcess-precision=fast -O2 -o fails $input -Wfatal-errors -Wall -Wextra -Werror -Wpedantic
if ! test "$?" = "0"; then
  exit 1
fi
( ulimit -t 10; ./fails )
if test "$?" = "0"; then
  exit 1
fi
exit 0

# gcc '-DHWY_DISABLED_TARGETS=(HWY_SSE4|HWY_SSSE3|HWY_SSE2)' -E -P math_test.cc

