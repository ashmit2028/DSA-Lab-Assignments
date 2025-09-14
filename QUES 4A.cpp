#include <iostream>
#include<algorithm>
using namespace std;

void display_list(int data[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i] << "    ";
    }
    cout << endl;
}

void invert_list(int data[], int count){
    for(int start=0, end=count-1; start < count/2; start++, end--)
    {
        swap(data[start], data[end]);
    }
    display_list(data, count);
}

int main(){
    int val1, val2, num_elements;
    int num_array[10] = {10, 14, 7, 12, 8, 6};
    num_elements = 6;

    display_list(num_array, num_elements);
    
    invert_list(num_array, num_elements);
}