#include <iostream>

class map{
public :
    map();
    ~map();
    // operatr =

    // ** Iterators ** //
    void begin();
    void end();
    void rbegin();
    void rend();
    
    // ** capacity ** //
    void empty();
    void size();
    void max_size();

    // ** Element access ** //
    // operatro[]

    // ** Modifiers ** //
    void insert();
    void erase();
    void swap();
    void clear();

    // ** Observers ** //
    void key_comp();
    void value_comp();

    // ** Operations ** //
    void find();
    void count();
    void lower_bound();
    void upper_bound();
    void equal_range();

    // ** Allocator ** //
    void get_allocator();
private:
};