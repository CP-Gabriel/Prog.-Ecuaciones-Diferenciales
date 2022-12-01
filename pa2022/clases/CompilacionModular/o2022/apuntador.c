#include <stdio.h>

int main(void)
{
  int dato = 3;
  int *p;
  p =  &dato;
  printf ("\nDato contiene %i y ésta apuntado por p\n", dato);
  printf ("\np tiene asignada la dirección hexadecimal de dato y es %p\n", p);
  printf ("\n");
  return 0;
}
