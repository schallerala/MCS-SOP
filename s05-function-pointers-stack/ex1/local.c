/*-------------------------------------------------------------------------
Illustration of the scope (visibility) and lifetime of local variables

FILE : local.c
USAGE: ./progr_name

RESULT:
vol = 0, perm = 0
                   vol = 10, perm = 10
vol = 1, perm = 1


vol = 0, perm = 2
                   vol = 10, perm = 11
vol = 1, perm = 3

   
-------------------------------------------------------------------------*/

#include <stdio.h>

int h() { // Global
   auto   int vol=0;  // local, volatile (keyword 'auto' is optional)
   static int perm=0; // local, permanent

   printf("\nvol = %i, perm = %i\n", vol++, perm++);

   {
             int vol=10;  // local, volatile
      static int perm=10; // local, permanent

      printf("                   vol = %i, perm = %i\n", vol++, perm++);
   }

   printf("vol = %i, perm = %i\n\n", vol++, perm++);
   return 0;
}

int main() {
   h();
   h();
   return 0;
}
