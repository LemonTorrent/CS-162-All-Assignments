#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  

int main(){
    int size, value;
    string temp;
    srand (time(NULL));
    //int* ar = new int [100];

    //for (int i = i; i < 100; i++){
      //  ar[i] = i + 1;
    //}

    do{

        cout << "What size dynamic array would you like? ";
        cin >> size;
        if (size <= 0 || size > 25)
            cout << "Please enter value greater than 0 and less than or equal to 25. ";
    } while (size <= 0 || size > 25);

    int* arr = new int[size];

    for (int i = 0; i < size; i++){
        value = rand() % 100 + 1;
        arr[i] = value;
    }

    cout << "Values: " << endl;

    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

    // sort here:
    selectionSort(arr, size);

    cout << "Sorted Values: " << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

    bool is_prime;

    cout << "Prime numbers: ";
    for (int i = 0; i < size; i++){
        is_prime = true;
        for (int j = 2; j < arr[i]; j++){
            if (arr[i] % j == 0)
                is_prime = false;
        }
        if (is_prime == true)
            cout << arr[i] << "  ";
    }
    cout << endl;

    delete [] arr;
    return 0;
}