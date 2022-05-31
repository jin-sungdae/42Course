#ifndef __PAIR_HPP__
#define __PAIR_HPP__

namespace ft{
    template <class T1, class T2> 
    struct pair{
    public:
        typedef T1      first_type;
        typedef T2      second_type;
        first_type      first;
        second_type     second;

        pair();
        template<class U, class V>
            pair(const pair<U, V> &pr);
        pair(const first_type& one, const second_type& two);
        pair& operator=(const pair& p);
    };
    
    template<class T1, class T2>
    pair<T1, T2>::pair() : first(), second(){}

    
    template<class T1, class T2>
    template<class U, class V>
    pair<T1, T2>::pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

    template<class T1, class T2>
    pair<T1, T2>::pair(const first_type &a, const second_type &two) :first(a) , second(two){}


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
        return (one != two);
    }

    template <class T1, class T2>
    bool operator <(const pair<T1, T2>& one, const pair<T1, T2>& two){
        return (one.first<two.first || (!(two.first < one.first) && one.second < two.second));
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

    template <class T1, class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
}


#endif