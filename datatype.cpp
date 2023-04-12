#include <cstdio>

int main()
{
   int    a1 = 3;
   int    b1 = 4;
   auto   c1 = a1 + b1; // yields int
   
   double a2 = 3.0;
   int    b2 = 4;
   auto   c2 = a2 + b2; // yields double
}

