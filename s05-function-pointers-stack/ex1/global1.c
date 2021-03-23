/*----------------------------------------------------------------------------
DESCRIPTION: Illustration of 1) the scope (visibility) of global and semi-global
variables and functions, and 2) the difference between declaration and definition

FILES: global1.c and global2.c

COMPILATION : gcc global1.c global2.c -o global

USAGE: ./global

RESULT:
main: gl_v = 2, sg_v = 1
 g_f: gl_v = 2, sg_v = 2
sg_f defined in file global2.c: Hello 2
sg_f defined in file global1.c: Hello


----------------------------------------------------------------------------*/

#include <stdio.h>

extern int  g_v;      // global      (is defined in file global2.c, keyword 'extern' is mandatory)
static int sg_v = 1;  // semi-global (is defined here)


extern char c;

extern int  g_f();  // global      (is defined in file global2.c, keyword 'extern' can be omitted)
static int sg_f();  // semi-global (must be defined in this file)


int main()
{

   c = 'a';

   printf("main: g_v = %i, sg_v = %i\n", g_v, sg_v);

   g_f();
   sg_f();

   return 0;
}


static int sg_f()   // semi-global (defined here)
{
   printf("sg_f defined in file global1.c: Hello\n");
   return 0;
}
