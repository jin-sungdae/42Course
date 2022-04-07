#include <iostream>

template<typename  T>
class vector{
public :

    vector(size_t cap = DEFAULT_CAP) : arr(new T[cap]);
    vector(vector const & v);
    vector & operator=(vector const & v);
    ~vector();
    
    // ** iterators ** //
    void begin();
    void end();
    void rbegin();
    void rend();
    void cbegin();
    void cend();
    void crbegin();
    void crend();

    // ** capacity ** //
    void size();
    void max_size();
    void resize();
    void capacity();
    void empty();
    void reserve();
    

    // ** Element access ** //
    // operator[]
    void at();
    void front();
    void back();
    

    // ** modifiers ** //
    void assign();
    void push_back();
    void pop_back();
    void insert();
    void erase();
    void swap();
    
    // ** Allocator ** //
    void get_allocator();

    // ** Non-member function overloads ** //
    // relational operators
    // swap

    // ** Template specializeations ** //
    // vector<bool>
private:
    static constexpr size_t DEFAULT_CAP = 32;
    T* arr;
    size_t m_size;
    size_t m_capacity;
};