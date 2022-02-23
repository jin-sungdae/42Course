#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *arr, int arrSize, void (*fcCalledArr)(const T &)){
    for (int i = 0; i < arrSize; i++){
        fcCalledArr(arr[i]);
    }
}

#endif