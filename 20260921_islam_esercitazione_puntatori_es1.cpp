#include <iostream>
#include <cstdlib>
using namespace std;


void swap(int* ptr1, int* ptr2) {
    int num3= *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = num3;
    

}

int main () {
    
    int a=5;
    int b=10;
    
    int* ptrA= &a;
    int* ptrB= &b;
   cout << "Prima dello scambio:" <<endl;
   cout << "a = " << a << ", b = " << b <<endl;
   
   swap (ptrA, ptrB);
   
    cout << "Dopo lo scambio:" <<endl;
   cout << "a = " << a << ", b = " << b <<endl;
   
    
    return 0;
    system ("PAUSE");
}