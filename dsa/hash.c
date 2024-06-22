/*12. Given a File of N employee records with a set K of Keys (4-digit) which
uniquely determine the records in file F. Assume that file F is maintained in
memory by a Hash Table (HT) of m memory locations with L as the set of memory
addresses (2-digit) of locations in HT. Let the keys in K and addresses in L are
Integers. Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m
(remainder method), and implement hashing technique to map a given key K to the
address space L. Resolve the collision (if any) using linear probing.
*/
#include <stdio.h>
#include <stdlib.h>
#define max 5
int a[max], count = 0;
void display() {
  int i;
  printf("\n Hash table contents :\n");
  printf("Index\tData\n");
  for (i = 0; i < max; i++)
    printf("\n%d\t%d\n", i, a[i]);
}
void linear_probe(int index, int num) {
  int i;
  if (count == max) {
    printf("Hash table is full\n");
    return;
  } else if (a[index] == -1) {
    a[index] = num;
    count++;
  } else {
    printf("\n Collision detected");
    printf("\n Collision resolved through linear probe");
    for (i = index + 1; i < max; i++) {
      if (a[i] == -1) {
        a[i] = num;
        count++;
        return;
      }
    }
    for (i = 0; i < index; i++) {
      if (a[i] == -1) {
        a[i] = num;
        count++;
        return;
      }
    }
  }
}
int main() {
  int num, index, input, i;
  for (i = 0; i < max; i++)
    a[i] = -1;
  do {
    printf("\n Enter the number : ");
    scanf("%d", &num);
    index = -num % max;
    linear_probe(index, num);
    display();
    printf("\n Enter 1 to continue : ");
    scanf("%d", &input);
  } while (input == 1);
  return 0;
}
/*
output:


*/