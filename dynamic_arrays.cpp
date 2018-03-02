#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

const int size_of_array = 6;
const int max_size = 49;

//Creating array: o -> 49        0 -> 48        0 -> 47        0 -> 46        0 -> 45        0 -> 44  Deleting one digit after draw.
void creating_array(int ** my_array, int size_of_array){
    for (int i=0; i<size_of_array; i++){
        my_array[i] = new int [max_size-i];
        for (int j=0; j<max_size-i; j++){
            my_array[i][j] = 0;
        }
    }
}

void add_element(int ** my_array, int value, int left, int right){
    my_array[left][right] = value;
}
void show_all (int ** my_array, int size_of_array){
    for (int i=0; i<size_of_array; i++){
        cout << endl << "Part of array number: " << i << endl;
        for (int j=0; j<max_size-i; j++){
            cout << j << ": " << my_array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int found_element(int ** my_array, int number, int size_of, int left){
    int found=0;
    for (int i=0; i<size_of; i++){
        if (my_array[left][i]==number){
            found = i;
        }
    }

    return found;
}

void delete_element (int ** my_array, int size_of, int number){

    my_array[size_of][number] = 0;
}

void assign_array(int ** my_array, int max_size, int level){
    if (level <= 4){
        for (int i=0, j=0; i<max_size; i++){
            if (my_array[level][i]!=0){
                my_array[level+1][i] = my_array[level][i+j];
            }
            else{
                j++;
                my_array[level+1][i] = my_array[level][i+j];
            }
        }
    }
}


int main(int argc, char *argv[]){

    int ** my_array = new int * [size_of_array];
    creating_array(my_array, size_of_array);

    //Adding element to base.
    for (int i=0; i<max_size; i++){
        add_element(my_array, i+1, 0, i);
    }

    srand(time(NULL));
    int random_int=0;
    int drawed_int=0;

    int * drawn_numbers= new int [size_of_array];

    for (int level=0; level<size_of_array; level++){
        random_int = ((rand()%max_size-level)+1);
        drawed_int = found_element(my_array, random_int, max_size-level, level);
        drawn_numbers[level] = my_array[level][drawed_int];
        delete_element(my_array, level, drawed_int);
        assign_array(my_array, max_size-level, level);
    }

    show_all(my_array, size_of_array);

    for (int i=0; i<size_of_array; i++){
        cout << i+1 <<". : " << drawn_numbers[i] << endl;
    }

    //Deleting array.
    for (int i=0; i<size_of_array; i++){
        delete [] my_array[i];
    }
    delete [] my_array;

    return 0;
}
