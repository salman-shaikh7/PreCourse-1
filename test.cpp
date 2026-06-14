#include <bits/stdc++.h> 
using namespace std;


int binarySearch(){

    int size = 10;
    int arr[size] = {1, 3, 5, 7,10, 12, 14,51,13,1};

    int left_index = 0;
    int right_index = size-1;

    int target = 13;

    while (left_index <= right_index){

        int mid = (right_index - left_index)/2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] < target){
            left_index = mid+1;
        }
        if (arr[mid] > target){
            right_index = mid-1;
        }
    }

    return -1;
};

int main(){ 

    cout<<binarySearch()<<endl;

}