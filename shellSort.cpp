#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total){
        int current = cur_segment_total + segment_idx;
        int size = end - start;
        while(current < size){
            int temp = start[current];
            int walker = current - cur_segment_total;
            while(walker >= 0 && temp < start[walker]){
                start[walker + cur_segment_total] = start[walker];
                walker = walker - cur_segment_total;
            }
            start[walker+cur_segment_total] = temp;
            current += cur_segment_total;
        }
    }
public:
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
        while(num_phases){
            int k = num_segment_list[num_phases-1];
            cout<< k << " segments: ";
            while(k >= 1){
                int segment = 0;
                while (segment <= k){
                    sortSegment(start, end, segment, k);
                    segment += 1;
                }
                k = 0;
            }
            printArray(start, end);
            num_phases--;
        }
    }
};
int main(){
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    return 0;
}