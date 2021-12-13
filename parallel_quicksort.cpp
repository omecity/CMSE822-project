#include <iostream>
#include <omp.h> 
#include <unistd.h>
#include <ctime>

// std::random_device random_device;
// std::mt19937 random_engine(random_device());

int getFirstIndex();
int getLastIndex(int);
int getRandomIndex(int);
void fillArray(int [], int);
void printArray(int [], int);
void quicksort(int [], int, int);
int partition(int [], int, int);
void swap (int [], int, int);


using namespace std;

// parallel_quicksort.cpp

int main(int argc, char *argv[]) {

    int option, arr_size;
    double start, end, time_elapsed;

    /*
    if (argc != 3){
        cout << "Usage: <executable name> <pivot choice [1, 2, 3, or 4]> <array size>\n\n";
    }
    */

    // read in the choice of pivot selection strategy and array size
    // option = atoi(argv[1]);
    // arr_size = atoi(argv[2]);

    int arr[8] = {5, 10, 2, 4, 3, 5, 8, 1};
    // int arr[arr_size];
    int i;

    arr_size = 8;
    // fillArray(arr, arr_size);
    printArray(arr, arr_size);

    quicksort(arr, 0, 7);

    cout << "===================================== " << endl;
    printArray(arr, arr_size);
    // testing the values 
    /*
    i = getFirstIndex();
    cout << "The first index and element is : " << i << " and " << arr[i]<< endl;

    i = getLastIndex(arr_size);
    cout << "The last index and element is : " << i << " and " << arr[i]<< endl;

    i = getRandomIndex(arr_size);
    cout << "The random index and element is : " << i << " and " << arr[i]<< endl;
    */

    cout << " " << endl;
    cout << "Hello parallel world from all threads" << endl;  
    
    
    /*
    start = omp_get_wtime();
    #pragma omp parallel
    {
        int rank, num_of_threads;
        num_of_threads = omp_get_num_threads();
        rank = omp_get_thread_num();
        usleep(5000 * rank);        // to avoid race condition when printing
        if (rank == 0){
            cout << "Greetings from process " << rank << " out of " << num_of_threads << " -- I am MASTER of all " << endl;  
        }
        else {
            cout << "Greetings from process " << rank << " out of " << num_of_threads << endl; 
        }
    }
    end = omp_get_wtime();
    time_elapsed = end - start;

    // //print out the resulting elapsed time
    cout << "Time for parallel computation region: "<< time_elapsed << " seconds." << endl;
    cout << "Back to the sequential world." << endl;  
    */

    // int option, index, arr_size;
    cout << "  " << endl;    
    cout << "The pivot options are as copied below: " << endl;

    // cout << "       1 -- first element " << endl;
    // cout << "       2 -- last element " << endl;
    // cout << "       3 -- random element " << endl;
    // cout << "       4 -- parallel prefix operation " << endl;

    // cout << "Enter an integer between 1 and 4 to choose the pivot options you want : " ;
    // cin >> option;
    
    // If (option == 1){
    //     index = getFirstElement(arr);
    // }
    // else if (option == 2){
    //     index = getLastElement(arr);
    // }
    // else if (option == 3){
    //     index = getRandomElement(arr);
    // }
    // else{
    //     index = getPrefixElement(arr);
    // }


  return 0;
}

// print the elements of the array
// std::cout << "arr: ";
// std::copy(arr.begin(),arr.end(), std::ostream_iterator<int>(std::cout, ","));
// cout << "This is the first element" << endl;
// cout << "This is the first element" << endl;
// cout << "This is the first element" << endl;

int getFirstIndex(){      
   return 0;
}

int getLastIndex(int arr_size){      
   return arr_size-1;
}

int getRandomIndex(int arr_size){      
    srand(time(0));
    return rand()%arr_size;
}

void fillArray(int arr[], int arr_size){
    srand(time(0));
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand()%arr_size;
}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << "The elements of the array arr["<<i<<"] = " << arr[i] << endl;
}

void quicksort(int arr[], int left, int right){
    if (left < right){
        // int pivot = arr[left+right/2];
        // int idx = partition(arr,left,right,pivot);
        int idx = partition(arr,left,right);

        // sort the sub-arrays recursively
        quicksort(arr, left, idx-1);
        quicksort(arr, idx+1, right);
        // for (int i = 0; i < arr_size; i++)
            // cout << "The elements of the array is/are " << arr[i] << endl;
    }
}

// int partition(int arr[], int left, int right){
//     int pivot = arr[right];
//     while (left < right){
//         while (arr[left] < pivot){
//             left++;
//         }
//          while (arr[right] > pivot){
//             right--;
//         }
//         if (left <= right){
//             swap(arr[left],arr[right]);
//             left++;
//             right--;
//         }
//     }
//     return left;
// }

// // partition the array using last element as pivot
// int partition (int arr[], int low, int high) 
// { 
//     int pivot = arr[high];    // pivot 
//     int i = (low - 1);      
//     for (int j = low; j <= high- 1; j++) 
//     { 
//         //if current element is smaller than pivot, increment the low element
//         //swap elements at i and j
//         if (arr[j] <= pivot) 
//         { 
//             i++;    // increment index of smaller element 
//             swap(arr, i, j); 
//         } 
//     } 
//     swap(arr,i,high); 
//     return (i + 1); 
// } 

// public int Partition(int a[], int low, int high) {
//    int pivot, index, i;
//    index = low;
//    pivot = high;
//    for(i=low; i < high; i++) {
//       if(a[i] < a[pivot]) {
//          swap(&a[i], &a[index]);
//          index++;
//       }
//    }
//    swap(a[pivot], &a[index]);
//    return index;
// }

int partition(int arr[], int start, int end) {
    int i = start + 1;
    int pivot = arr[start] ;            
    for(int j = start + 1; j <= end ; j++ )  {
        if (arr[j] < pivot) {
                swap (arr,i,j);
            i = i + 1;
        }
   }
   //put the pivot element in its proper place.
   swap (arr,start,i-1) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

void swap(int arr[], int left, int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
} 