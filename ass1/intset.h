#ifndef intset_h
#define intset_h
#include <iostream>


class IntSet {
   public:
   IntSet();                            // Empty Constructor
   ~IntSet();                           // Destructor
   //IntSet(const IntSet *copy);          // Copy Constructor
   //IntSet(int num1);                    // X num Constructor 1-5
   //IntSet(int num1, int num2);
   //IntSet(int num1, int num2, int num3);
   //IntSet(int num1, int num2, int num3, int num4);
   //IntSet(int num1, int num2, int num3, int num4, int num5);

   bool insert(int num);
   bool remove(int num);
   bool isEmpty() const;
   bool isInSet(int num) const;
   void printSet() const;
   void printSetArray() const;

   bool* operator +(const IntSet& other);
   bool* operator *(const IntSet& other);
   bool* operator -(const IntSet& other);
   void operator =(const IntSet& other);
   void operator +=(const IntSet& other);
   void operator *=(const IntSet& other);
   void operator -=(const IntSet& other);
   bool operator ==(const IntSet& other);
   bool operator !=(const IntSet& other);
   friend std::ostream& operator <<(std::ostream& os, const IntSet& intset);


   bool* getSet() const;
   int getArraySize() const;
   private:
   bool* set;
   int max_value;
   int array_size;
   int total_true;

   
   int findMax() const;

};

#endif