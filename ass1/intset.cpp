#include "intset.h"
#include <iostream>

IntSet::IntSet() {
   set = new bool[2]();
   max_value = 0;
   array_size = 1;
   total_true = 0;
}

IntSet::~IntSet() {
   delete[] set;
   set = nullptr;
}

bool IntSet::insert(int num) {
   if (num < 0) { return false; }

   if (num > max_value) {
      bool* new_set = new bool[num + 1]();
      for (int i = 0; i <= max_value; i++) {
         new_set[i] = set[i];
      }
      delete[] set;
      set = new_set;
      new_set = nullptr;
      max_value = num;
      array_size = num + 1;
   }
   set[num] = true;
   total_true++;
   return true;
}

bool IntSet::remove(int num) {
   if (num < 0) { return false; }
   if (num > max_value) { return true; }
   if (num <= max_value && set[num] == true) {
      total_true--;
   }
   set[num] = false;
   if (num == max_value) {
      max_value = findMax();
      array_size = max_value + 1;
      bool* replacement_set = new bool[array_size]();
      for (int i = 0; i < array_size; i++) {
         if (set[i] == true) {
            replacement_set[i] = true;
         }
      }
      delete[] set;
      set = replacement_set;
      replacement_set = nullptr;
   }
   return true;
}

bool IntSet::isEmpty() const {
   for (int i = 0; i < array_size; i++) {
      if (set[i] == true) {
         return false;
      }
   }
   return true;
}

int IntSet::findMax() const {
   for (int i = max_value; i >= 0; i--) {
      if (set[i] == true) {
         return i;
      }
   }
   return 0;
}

bool IntSet::isInSet(int num) const {
   if (num > max_value || num < 0) {
      return false;
   }
   if (set[num] == true) {
      return true;
   }

   return false;
}

int IntSet::getArraySize() const {
   return array_size;
}

void IntSet::printSet() const {
   for (int i = 0; i < array_size; i++) {
      
      if (set[i] == true) {
         std::cout << i << " ";
      }
      
   }
   std::cout << std::endl;
}

void IntSet::printSetArray() const {
   for (int i = 0; i < array_size; i++) {
      if (set[i] == true) {
         std::cout << "t" << " ";
      } else {
         std::cout << "f" << " ";
      }
   }
   std::cout << std::endl;
}

bool* IntSet::getSet() const {
   return set;
}

bool* IntSet::operator+(const IntSet& other) {
   IntSet temp = IntSet();
   for (int i = 0; i < array_size; i++) {
      if (set[i] == true) { temp.insert(i); }
   }
   for (int i = 0; i < other.array_size; i++) {
      if (other.set[i] == true) { temp.insert(i); }
   }
   std::cout << "+ operator: ";
   temp.printSet();
   std::cout << std::endl;
   return temp.set;
}

void IntSet::operator+=(const IntSet& other) {
   int greater_array_size = 0;
   if (array_size > other.array_size) {
      greater_array_size = array_size;
   } else {
      greater_array_size = other.array_size;
   }

   IntSet temp = IntSet();
   bool* replacement_set = new bool[greater_array_size]();
   for (int i = 0; i < array_size; i++) {
      if (set[i] == true) {
         replacement_set[i] = true;
      }
   }
   
   for (int i = 0; i < other.array_size; i++) {
      if (other.set[i] == true) {
         replacement_set[i] = true;
      }
   }

   delete[] set;
   set = replacement_set;
   replacement_set = nullptr;
   array_size = greater_array_size;
   max_value = greater_array_size - 1;

   std::cout << "+= operator: ";
   printSet();
   std::cout << std::endl;
}

bool* IntSet::operator*(const IntSet& other) {
   int lower_array_size = 0;
   if (array_size < other.array_size) { 
      lower_array_size = array_size;
   } else {
      lower_array_size = other.array_size;
   }
   IntSet temp = IntSet();
   for (int i = 0; i < lower_array_size; i++) {
      if (set[i] == true && other.set[i] == true) {
         temp.insert(i);
      }
   }
   std::cout << "* operator: ";
   temp.printSet();
   std::cout << std::endl;
   return temp.set;
}

void IntSet::operator*=(const IntSet& other) {
   int lower_array_size = 0;
   if (array_size < other.array_size) {
      lower_array_size = array_size;
   } else {
      lower_array_size = other.array_size;
   }
   bool* replacement_set = new bool[lower_array_size]();
   for (int i = 0; i < lower_array_size; i++) {
      if (set[i] == true && other.set[i] == true) {
         replacement_set[i] = true;
      }
   }

   delete[] set;
   set = replacement_set;
   array_size = lower_array_size;
   max_value = array_size - 1;

   std::cout << "*= operator: ";
   printSet();
   std::cout << std::endl;
}

bool* IntSet::operator-(const IntSet& other) {
   IntSet temp = IntSet();
   for (int i = 0; i < array_size; i++) {
      if (i < other.array_size && set[i] == true && other.set[i] == false) {
         temp.insert(i);
      }
   }
   std::cout << "- operator: ";
   temp.printSet();
   std::cout << std::endl;
   return temp.set;
}

void IntSet::operator-=(const IntSet& other) {
   bool* replacement_set = new bool[array_size]();
   for (int i = 0; i < array_size; i++) {
      if (set[i] == true && other.set[i] == false) {
         replacement_set[i] = true;
      }
   }
   delete[] set;
   set = replacement_set;

   std::cout << "-= operator: ";
   printSet();
   std::cout << std::endl;
}

void IntSet::operator=(const IntSet& other) {
   delete[] set;
   bool* temp_set = new bool[other.array_size]();
   for (int i = 0; i < other.array_size; i++) {
      if (other.set[i] == true) {
         temp_set[i] = true;
      }
   }
   set = temp_set;
   max_value = other.max_value;
   array_size = other.array_size;
   total_true = other.total_true;
   std::cout << "= operator: ";
   printSet();
   std::cout << std::endl;
}

bool IntSet::operator==(const IntSet& other) {
   if (max_value != other.max_value) {
      return false;
   }

   for (int i = 0; i < array_size; i++) {
      if (set[i] != other.set[i]) {
         return false;
      }
   }

   return true;
}

bool IntSet::operator!=(const IntSet& other) {
   return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const IntSet& intset) {
   os << "{";
   
   for (int i = 0; i < intset.getArraySize(); i++) {
      if (intset.getSet()[i] == true) {
         os << " " << i;
      }
   }
   
   os << "}";

   return os;
}