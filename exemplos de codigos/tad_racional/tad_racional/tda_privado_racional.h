#ifndef privado_racional_h
#define privado_racional_h

#include "tda_interface_racional.h"

/* estruturas privativas ao TDA */
struct racional {
	int num;
	int dem;
};

/* operações privativas ao TDA */
int mdc(int a, int b);

#endif
