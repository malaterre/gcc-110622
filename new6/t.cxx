#include <iostream>
#include <cstdint>
#include <cstring>
int main()
{
uint64_t start = 4318952042648305665;
uint64_t stop = 4368493837572636672;
double dstart;
double dstop;
memcpy(&dstart, &start, sizeof dstart);
memcpy(&dstop, &stop, sizeof dstop);
std::cout << dstart << std::endl;
std::cout << dstop << std::endl;
long double ddstart = dstart, ddstop = dstop;
std::cout << ddstart << std::endl;
std::cout << ddstop << std::endl;

fprintf(stderr, "%a %La\n", dstart, ddstart);
fprintf(stderr, "%a %La\n", dstop, ddstop);

}
