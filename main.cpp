#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int list[], int left, int right){
     if(left < right){
                  int low = left;
                  int high = right;
                  int key = list[left];
     
                  while(left < right){
                             while(left < right && list[right] >= key)
                                        right--;
                             list[left] = list[right];
                             while(left < right && list[left] <= key)
                                        left++;
                             list[right] = list[left];
                  }
                  list[left] = key;
     
                  quick_sort(list, low, left-1);
                  quick_sort(list, left+1, high);
     }
}

void merge(int list[], int left, int mid, int right){
     int i = left;
     int j = mid + 1;
     int num = right - left + 1;
     int temp[num];
     int k = 0;
     while(i <= mid && j <= right)
            temp[k++] = list[i] < list[j]?list[i++]:list[j++];

     while(i <= mid)
          temp[k++] = list[i++];
     while(j <= right) 
          temp[k++] = list[j++];
          
     for (int i = 0; i < num; i++)  
        list[left + i] = temp[i];  
}

void merge_sort(int list[], int left, int right){
     if(left < right){
             int mid = (left + right) >> 1;
             merge_sort(list, left, mid);
             merge_sort(list, mid+1, right);
             
             merge(list, left, mid, right);             
     }
}

int binary_search(int list[], int length, int key){
     
     int left = 0;
     int right = length - 1;
     
     while(left <= right){
                //int mid = left + ((right - left + 1) >> 1);
                int mid = (left + right) >> 1;
                if(key < list[mid])
                       right = mid -1;             
                else if(key > list[mid])
                     left = mid + 1;
                else
                    return mid;           
     }
     return -1;
}





int main(int argc, char *argv[])
{
    
    int list[8] = {4, 7, 8, 2, 9, 1, 3, 5};
    int length = sizeof(list) / sizeof(int);
    
        
    for(int i = 0; i < length; i++)
            cout << list[i];
    cout<<endl;
    
    //quick_sort(list, 0, length-1);
    merge_sort(list, 0, length - 1);
    //MergeSort(list, 0, length - 1);
    
    for(int i = 0; i < length; i++)
            cout << list[i];
    cout<<endl;
    
    int pos = binary_search(list, length, 3);
    cout << pos << endl;
    
    cout << "Hello World";
    system("PAUSE");
    return EXIT_SUCCESS;
}
