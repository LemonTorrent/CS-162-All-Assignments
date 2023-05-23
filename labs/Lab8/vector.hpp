#include <stdlib.h>
#include <cassert>
#include <iostream>
//using namespace std;

using std::cout;
using std::endl;

template <class T>
class vector {
   private:
      T *v;
      int s;
      int capacity;

   public:
      vector(){
             s=0;
             v=NULL;
      }
 
      ~vector(){
             delete [] v;
      }

      int size() {
             return s;
      }

      void push_back(T ele, int c) {
             capacity = c;
             T *temp;
             temp = new T[capacity];
             for(int i=0; i < s; i++)
                temp[i]=v[i];
             delete [] v;
             v=temp;
             v[s]=ele;
             s +=1
      }

      void push_back(T ele) {
             if (capacity > s){
                T *temp;
                temp = new T[s + 1];
                for(int i=0; i < s; i++)
                    temp[i]=v[i];
                delete [] v;
                v=temp;
             }

             s += 1;
             v[s-1]=ele;
      }

      vector(vector<T> &other){
            int temp_s = other.get_s();
            T* temp = new T[temp_s];
            for (int i=0; i<temp_s; i++){
                temp[i]  = other.get_element(i); //other.v[i]
            }
            //delete [] v;
            v = temp;
            s = temp_s;
      }

      void operator=(vector<T> &other){
            int temp_s = other.get_s();
            T* temp = new T[temp_s];
            for (int i=0; i<temp_s; i++){
                temp[i]  = other.get_element(i);
            }
            delete [] v;
            v = temp;
            s = temp_s;
      }

      int get_s(){
          return s;
      }

      T get_element(int i){
          return v[i];
      }

      T& operator[](int i){
          return v[i];
      } //Only performs address arithmetic

      T& at(int i){
          assert(i >= 0 && i < s);  //generally throw out of range error
          //if (i >= 0 && i < s) //don't need
          return v[i];
          //cout << "Out of bounds" << endl;
          //exit();
          //return -1;
      }         //Check to make sure not out of bounds

      void resize(int c){
          capacity = c;
          if (capacity > s){
            T *temp;
            temp = new T[capacity];
            for(int i=0; i < s; i++)
               temp[i]=v[i];
            delete [] v;
            v=temp;
          } else {
            cout << "Capacity is smaller than current capacity" << endl;
          }
      }
};

