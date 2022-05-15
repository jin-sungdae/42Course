#include <map>
#include <iostream>
#include <time.h>
#include "define.hpp"
#include "map.hpp"
#include "map_iterator.hpp"
#include <string>

template<typename T1, typename T2>
void print_map(ft::map<T1, T2> map) {
	typename ft::map<T1, T2>::const_iterator start = map.begin();
	typename ft::map<T1, T2>::const_iterator end = map.end();


	std::cout << "[ " ;
	while (start != end) {
		std::cout << start->first << " : " << start->second << ", ";
		start++;
	}
	std::cout << " ]" << std::endl;
}


int main(void) {
	clock_t start, end;
	start = clock();

	std::cout << "=====================================" << std::endl;
	std::cout << "===============[ MAP ]===============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	{
		std::cout << "> default constructor" << std::endl;

		ft::map<int, std::string> m1;
	
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> range constructor" << std::endl;
		std::cout << "> 1: one, 2: two, 3: three 추가" << std::endl;
		m1[1] = "one";
		m1[2] = "two";
		m1[3] = "three";
		ft::map<int, std::string> m2(m1.begin(), m1.end());

		std::cout << "😎 m  ( size : " << m2.size() << " )" << std::endl;
		print_map(m2);
		std::cout << std::endl;
		
		std::cout << "> copy constructor" << std::endl;

		ft::map<int, std::string> m3(m2);

		std::cout << "😎 m  ( size : " << m3.size() << " )" << std::endl;
		print_map(m3);
		std::cout << std::endl;

		std::cout << "> operator = " << std::endl;
		ft::map<int, std::string> m4 = m3;

		std::cout << "😎 m  ( size : " << m4.size() << " )" << std::endl;
		print_map(m4);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Iterators " << std::endl;
	{
		ft::map<int, std::string> m1;

		m1[1] = "one";
		m1[2] = "two";
		m1[3] = "three";

		std::cout <<"adfasfdasdfsafdasdf : ++++++" << m1[1] <<std::endl;

		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;
		std::cout << "> begin " << std::endl;
		std::cout << "😎 m.begin()  => " << m1.begin()->first << " : " << m1.begin()->second << std::endl;
		std::cout << std::endl;
		std::cout << "> end " << std::endl;
		std::cout << "😎 m.end() - 1  => " << (--m1.end())->first << " : " << (--m1.end())->second << std::endl;
		std::cout << std::endl;
		std::cout << "> rbegin " << std::endl;
		std::cout << "😎 m.rbegin()  => " << m1.rbegin()->first << " : " << m1.rbegin()->second << std::endl;
		std::cout << std::endl;
		std::cout << "> rend " << std::endl;
		std::cout << "😎 m.rend() - 1  => " << (--m1.rend())->first << " : " << (--m1.rend())->second << std::endl;
		std::cout << std::endl;

		std::cout << "> itertor 로 출력" << std::endl;
		std::cout << "😎 m " << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> reverse itertor 로 출력" << std::endl;
		ft::map<int, std::string>::reverse_iterator m_rit = m1.rbegin();

		std::cout << "😎 m " << std::endl;
		while (m_rit != m1.rend()) {
			std::cout << m_rit->first << " : " << m_rit->second << std::endl;
			m_rit++;
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------- Capacity " << std::endl;
	{
		ft::map<int, std::string> m1;
		std::cout << "> empty - 비어있는 경우" << std::endl;
		std::cout << "😎 m " << std::endl;
		print_map(m1);
		std::cout << std::endl;
		std::cout << "😎 m1.empty() => " << m1.empty() << std::endl;
		std::cout << std::endl;

		std::cout << "> empty - 비어있지 않은 경우 " << std::endl;
		m1[1] = "hi";
		std::cout << "😎 m " << std::endl;
		print_map(m1);
		std::cout << std::endl;
		std::cout << "😎 m1.empty() => " << m1.empty() << std::endl;
		std::cout << std::endl;

		std::cout << "> size " << std::endl;
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> size - 요소 3개 추가" << std::endl;
		m1[2] = "hoylee2";
		m1[3] = "hoylee3";
		m1[4] = "hoylee4";
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> max_size " << std::endl;
		std::cout << "😎 m.max_size()  => " << m1.max_size() << std::endl;
		std::cout << std::endl;

		std::cout << "----------------------- Element access " << std::endl;
		std::cout << "> operator[] " << std::endl;
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);

		std::cout << "😎 m[1] : " << m1[1] << std::endl;
		std::cout << "😎 m[2] : " << m1[2] << std::endl;
		std::cout << "😎 m[3] : " << m1[3] << std::endl;
		std::cout << "😎 m[4] : " << m1[4] << std::endl;

	}

	std::cout << "----------------------- Modifiers " << std::endl;
	{
		ft::map<std::string, int> m1;
		std::cout << "> insert1 " << std::endl;
		std::cout << "> [hoylee, 42] 추가 " << std::endl;
		ft::pair<ft::map<std::string, int>::iterator, bool> m_pair;
		std::cout << "=====================" << std::endl;
		m_pair = m1.insert(ft::make_pair<std::string, int>("hoylee", 42));

		ft::map<std::string, int>::iterator m1_i= m1.begin();
		m1.insert(ft::make_pair<std::string, int>("adylee", 52));
		std::cout << "😎 m_i  ( m1_iter : " << (*(m1_i)).first << " )" << std::endl;
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << "insert return : " << m_pair.second << std::endl;
		std::cout << std::endl;

		std::cout << "> 같은 key 한번 더 insert" << std::endl;
		m_pair = m1.insert(ft::make_pair<std::string, int>("hoylee", 42));

		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << "insert return : " << m_pair.second << std::endl;
		std::cout << std::endl;

		std::cout << "> insert2 [yong: 100]" << std::endl;
		m1.insert(m1.begin(), ft::pair<std::string, int>("yong", 100));

		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> insert3 [one: 1, two: 2, three:3] " << std::endl;
		ft::map<std::string, int> m2;

		m2["one"] = 1;
		m2["two"] = 2;
		m2["three"] = 3;
		
		m1.insert(m2.begin(), m2.end());
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> erase1 - begin()" << std::endl;
		m1.erase(m1.begin());
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

//		std::cout << "> erase2 key - yong" << std::endl;
//		std1.erase("yong");
//		m1.erase("yong");
////		//설명 : 이거 ambigous 에러나는데, 못잡겠음 .ㅠ.ㅠ.ㅠ.ㅠ.ㅠ.ㅠ.ㅠ :
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;
		std::cout << "> erase3 begin(), ++begin()" <<  std::endl;

		m1.erase(m1.begin(), (++m1.begin()));
		std::cout << "😎 m  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;

		std::cout << "> swap " << std::endl;
		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << "😎 m2  ( size : " << m2.size() << " )" << std::endl;
		print_map(m2);
		std::cout << std::endl;
		std::cout << "> 1.swap(2)" << std::endl;
		m1.swap(m2);
		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << "😎 m2  ( size : " << m2.size() << " )" << std::endl;
		print_map(m2);
		std::cout << std::endl;

		std::cout << "> clear 1" << std::endl;
		m1.clear();
		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Observers " << std::endl;
	{
		ft::map<std::string, int> m1;
		ft::map<std::string, int>::key_compare m_comp = m1.key_comp();

		m1["abc"] = 100;
		m1["aaa"] = 200;
		m1["abd"] = 300;

		std::string highest2 = m1.rbegin()->first;

		std::cout << "> key_comp " << std::endl;
		ft::map<std::string,int>::iterator m_it = m1.begin();

		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		do {
			std::cout << m_comp((*m_it).first, highest2) << std::endl;
			std::cout << m_it->first << " => " << m_it->second << '\n';
		} while ( m_comp((*m_it++).first, highest2) );
		std::cout << std::endl;

		std::cout << "> value_comp " << std::endl;

		m_it = m1.begin();

		ft::pair<std::string, int> v_highest2 = *m1.rbegin();

		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		do {
			std::cout << m1.value_comp()(*m_it, v_highest2) << std::endl;
			std::cout << m_it->first << " => " << m_it->second << '\n';
		} while ( m1.value_comp()(*m_it++, v_highest2) );
		std::cout << std::endl;
	}

	std::cout << "----------------------- Operations " << std::endl;
	{
		ft::map<int, std::string> m1;

		m1[0] = "zero";
		m1[1] = "one";
		m1[2] = "two";


		std::cout << "> find " << std::endl;
		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);
		std::cout << "😎 m1.find(0) => " << m1.find(0)->second << std::endl;
		std::cout << "😎 m1.find(1) => " << m1.find(1)->second << std::endl;
		std::cout << "😎 m1.find(2) => " << m1.find(2)->second << std::endl;
		std::cout << std::endl;

		std::cout << "> count " << std::endl;
		for (int i = -1; i < 4; i++) {
			std::cout << "😎 m1.find(" << i << ") => ";
			if (m1.count(i) > 0)
				std::cout << "is an element" << std::endl;
			else
				std::cout << "is not an element" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "> lower_bound " << std::endl;
		m1[4] = "four";
		m1[6] = "six";
		m1[8] = "eight";
		std::cout << "😎 m1  ( size : " << m1.size() << " )" << std::endl;
		print_map(m1);

		std::cout << "😎 m1.lower_bound(3)  => " << m1.lower_bound(3)->first << " : " << m1.lower_bound(3)->second << std::endl;
		std::cout << std::endl;

		std::cout << "> upper_bound " << std::endl;
		std::cout << "😎 m1.upper_bound(3)  => " << m1.upper_bound(3)->first << " : " << m1.upper_bound(3)->second << std::endl;
		std::cout << std::endl;
		std::cout << "> equal_range " << std::endl;
		ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> m_it_pair;
		m_it_pair = m1.equal_range(1);
		std::cout << "😎 m  : " << m_it_pair.first->first << " => " << m_it_pair.first->second << std::endl;
		std::cout << "😎 m  : " << m_it_pair.second->first << " => " << m_it_pair.second->second << std::endl;
		std::cout << std::endl;
	}

	std::cout << "----------------------- Allocator " << std::endl;
	{
		std::cout << "> get_allocator " << std::endl;
		int m_size;
		ft::map<char, int> m1;
		ft::pair<const char, int>* m_p;

		m_p = m1.get_allocator().allocate(5);

		m_size = sizeof(ft::map<char,int>::value_type) * 5;

		std::cout << "😎 m  : The allocated array has a size of " << m_size << " bytes.\n";

		m1.get_allocator().deallocate(m_p, 5);

	}
    end = clock();
    std::cout << "result : " << (double)(end - start) << std::endl;
}
