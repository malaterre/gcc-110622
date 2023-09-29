#!/bin/sh -x
g++ -Wall -Wextra -Werror -c cast.cc && g++  -Wcast-align=strict -Wfatal-errors -Werror -c cast.cc 2>&1 | grep --fixed-strings "error: cast from ‘hwy::bfloat16_t* __restrict__’ to ‘uint16_t*’ {aka ‘short unsigned int*’} increases required alignment of target type [-Werror=cast-align]"
