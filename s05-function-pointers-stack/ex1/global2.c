/*----------------------------------------------------------------------------
DESCRIPTION : see global1.c

   
----------------------------------------------------------------------------*/
#include <stdio.h>

int g_v = 2;            // global (declared as extern in file global1.c and defined here)

static int sg_v = 2;    // semi-global (is defined here)
static int sg_f(int x); // semi-global (must be defined in this file)

int g_f() // global (declared in file global1.c and defined here)
{
   printf(" g_f: g_v = %i, sg_v = %i\n", g_v, sg_v);
   sg_f(sg_v);
   return 0;
}

static int sg_f(int x) // semi-global
{
   printf("sg_f defined in file global2.c: Hello %i\n", x);
   return 0;
}
