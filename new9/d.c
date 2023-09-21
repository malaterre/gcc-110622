#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
uint64_t start = 4318952042648305665;
uint64_t stop = 4368493837572636672;
double dstart;
double dstop;
memcpy(&dstart, &start, sizeof dstart);
memcpy(&dstop, &stop, sizeof dstop);
	printf( "%" PRIu64 " - %a %.17g\n", start, dstart, dstart );
	printf( "%" PRIu64 " - %a %.17g\n", stop, dstop, dstop );
}
