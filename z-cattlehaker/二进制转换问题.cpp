#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include "stdio.h"

int main(){
	signed int i = -214748368;
	return printf("%d\n,%d\n,%d\n,%d\n",~i, -i, 1 - i, -1 - i);
}

#endif