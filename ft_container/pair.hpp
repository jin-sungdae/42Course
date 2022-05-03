#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{
    template <class T1, class T2> 
    struct pair{
        public:
        typedef T1      first_type;
        typedef T2      second_type;
        first_type      first;
        second_type     second;
        template<class U, class V>
            pair(const pair<U, V> &pr);
        pair(const pair& one, const pair& two);
        pair& operator=(const pair& p);
        pair();

    };
    template<class T1, class T2>
    pair<T1, T2>::pair() : first(), second(){}

    template<class T1, class T2>
    pair<T1, T2>::pair(const pair&a, const pair& two) :first(a) , second(two){}

    template<class T1, class T2>
    template<class U, class V>
    pair<T1, T2>::pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

    template<class T1, class T2>
    pair<T1, T2>& pair<T1, T2>::operator=(const pair& p){
        first = p.first;
        second = p.second;
        return *this;
    }

    template<class T1, class T2>
    bool operator==(const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one.first == two.first && one.second == two.second);
    }

    template<class T1, class T2>
    bool operator!=(const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one != two)
    }

    template <class T1, class T2>
    bool operator <(const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one > two);
    }

    template <class T1, class T2>
    bool operator <= (const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one <= two);
    }

    template <class T1, class T2>
    bool operator > (const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one > two);
    }

    template <class T1, class T2>
    bool operator >= (const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one >= two);
    }
}


#endif