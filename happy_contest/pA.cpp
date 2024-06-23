//#include "my_strcmp.h"
#include <cstdio>
#include <string.h>

const int hehe = 48763;

int my_strcmp(char *a, char *b) {
	int x = 0;
	int *ptr = (int*)&x;
	while(*ptr != hehe) {
		ptr++;
	} 
	//ptr -= sizeof(int);
	int res = (strcmp(a, b) ? 1 : 0);
	
	char buffer[128];
    snprintf(buffer, sizeof(buffer), "S: %d", &ptr);

	*ptr = res;
	return 0;
}
