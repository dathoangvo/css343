#include "intset.h"
#include <iostream>

int main() {
   IntSet A = IntSet();
   IntSet B = IntSet();

   /*
   A.insert(3);
   A.printSetArray();
   A.remove(3);
   A.printSetArray();
   A.insert(3);
   A.insert(6);
   A.remove(3);
   A.printSetArray();
   */

   
   A.insert(2);
   A.insert(3);
   A.insert(5);
   A.insert(8);
   A.insert(10);
   A.insert(12);

   B.insert(2);
   B.insert(5);
   B.insert(9);
   //B.insert(11);

   //A -= B;
   //std::cout << (A != B) << std::endl;

   std::cout << A << std::endl;
   int num;
   std::cin >> num;
   return 0;
}