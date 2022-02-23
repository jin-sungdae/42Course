#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b){
    T tmp = a;

    a = b;
    b = tmp;
}

template<typename T>
const T &min(T const &a, T const &b){
    if (a > b){
        return b;
    }
    return a;
}

template<typename T>
const T &max(T const &a, T const &b){
    if (a > b){
        return a;
    }
    return b;
}

#endif