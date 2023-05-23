#include "./vector.hpp"
#include <vector>
#include <iostream>
#include <cassert>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;
//using namespace std;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);

   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
   //cout << stdv.at(2) << endl;

   v.push_back(24);

   vector<int> w(v);
   cout << "W vector size: " << w.size() << endl;

   v.push_back(25);
   vector<int> z;
   z = v;
   cout << "Z vector size:" << z.size() << endl;
   int capacity = 5;
   z.push_back(26, capacity);
   cout << "Z vector size:" << z.size() << endl;
   cout << "Z at 3: " << z[3] << endl;
   cout << "Z at 4: " << z[4] << endl;

   w.resize(4);
   cout << "W vector size: " << w.size() << endl;


   //cout << z[1] << endl;
   //cout << z.at(-1) << endl;

   return 0;
}