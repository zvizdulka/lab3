#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

int partition(vector<int> &arr, int left, int right){
    int i = left, j = right;
    int pivot = arr[left];
    while((i < j) && arr[j] >= pivot){
        --j;
    }
    int k = j;
    while(i < j){
        while((i < j) && arr[i] < pivot){
            ++i;
        }
        while((i < j) && arr[j] >= pivot){
            --j;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    if(i != k){
        swap(arr[i], arr[k]);
    }
    return i ;
}

void quicksort(vector<int> &arr, int left, int right){
    int index = partition(arr, left, right);
    if (left < index - 1){
        quicksort(arr, left, index - 1);
    }
    if (index + 1 < right){
        quicksort(arr, index + 1, right);
    }
}

int main(int argc, const char * argv[]){
    try{
        vector < int > array;
        ifstream in(argv[1]);
        if (in.is_open()){
            while (!in.eof()){
                int i;
                in >> i;
                array.push_back(i);
            }
        }
        else{
            throw invalid_argument("File not found.");
        }
        in.close();
        clock_t start = clock();
        quicksort(array, 0, (int)array.size() - 1);
        clock_t end = (int)clock();
        cout << "Процессорное время: " << end - start << endl;
        ofstream out;
        out.open("sort.txt");
        if (out.is_open()){
            for(int i = 0; i < array.size(); i++)
                out << array[i] << " ";
        }
        out.close();
    }
    catch(invalid_argument err){
        cout << err.what() << endl;
    }
}

