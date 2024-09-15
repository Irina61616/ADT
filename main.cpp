//1. cd /Users/macbookpro/Documents
//2. ls main.cpp
//3. g++ main.cpp -o main_executable
//4. ./main_executable

#include <iostream>
#include <string>

using namespace std;

class set 
{
public:
    set(){}


    set(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    set(int size, int *arr)
    {
        this->size = size;
        for(int i = 0; i < size; ++i)
        {
            this->arr[i] = arr[i];
        }
    }

    bool is_equal(set s)
    {
        
        if (this->size != s.size)
        {
            return false;
        }
        else
        {
            for (int i = 0 ;i < this->size; ++i)
            {
                if(this->arr[i] != s.arr[i])
                {
                    return false;
                    break;
                }
            }
            return true;
        }
    }

    set unit_sets(set s)
    {
        set new_set((this->size + s.size));

        for (int i = 0; i < (this->size + s.size); ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                for(int k = 0; k < s.size; ++k)
                {
                    if (i < this->size)
                    {
                        new_set.arr[i] = this->arr[j];
                    }
                    else if (i >= this->size && i < s.size)
                    {
                        new_set.arr[i] = s.arr[k];
                    }
                }
            }
        }
    for(int i = 0; i < this->size; ++i)
    {
        cout << new_set.arr[i] << "\t";
    }
    cout << endl;
        return new_set;
    }

set intersect_sets(set s)
{
    set new_set(this->size);
    for (int i = 0; i < this->size; ++i)
    {
        for(int j = 0; j < s.size; ++j)
        {
            if (this->arr[i] == s.arr[j])
            {
                new_set.arr[i] = this->arr[i];
            }
        }
    }
    for(int i = 0; i < this->size; ++i)
    {
        cout << new_set.arr[i] << "\t";
    }
    cout << endl;
    return new_set;
}
~set ()
{
    delete [] arr;
    size = 0;
}
private:
    int size;
    int* arr;
};

int main() {

    int arr[3] = {1, 2, 3};
    int arr1[2] = {1, 5};

    set s(3, arr);
    set s1(2, arr1);

    cout << "Are sets equal? " << s.is_equal(s1) << endl;
    s.intersect_sets(s1);
    s.unit_sets(s1);

    return 0;
}