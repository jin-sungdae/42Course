#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "vector.hpp"
#include "vector_iterator.hpp"
#include "../util/define.hpp"


template<typename T>
void print_vector(TESTED_NAMESPACE::vector<T>& v) {
	typename TESTED_NAMESPACE::vector<T>::const_iterator iter;
	
	std::cout << "[ ";
	for (iter = v.begin(); iter != v.end(); ++iter) {
		std::cout << *iter;
		if (iter + 1 != v.end()) {
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

int main() {
	clock_t start, end;
	start = clock();
	std::cout << "=====================================" << std::endl;
	std::cout << "==============[ VECTOR ]=============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	{
		std::cout << "  [ default constructor test ]" << std::endl;
		TESTED_NAMESPACE::vector<int> ft1;
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ fill constructor test ]" << std::endl;
		TESTED_NAMESPACE::vector<int> ft2(5, 3);
		std::cout << "😎 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ range constructor test ]" << std::endl;
		std::cout << "> first(begin + 1), last(end - 1)" << std::endl;
		TESTED_NAMESPACE::vector<int> ft3(ft2.begin() + 1, ft2.end() - 1);
		std::cout << "😎 ft  ( size : " << ft3.size() << " )" << std::endl;
		print_vector(ft3);
		std::cout << std::endl;
	}
	std::cout << "  [ Assign test ]" << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 42);
		TESTED_NAMESPACE::vector<int> ft2;

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 2 = 1 로 할당" << std::endl;
		ft2 = ft1;

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 2.push_back(2) 로 깊은복사 체크" << std::endl;
		ft2.push_back(2);
		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Iterator " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1;
		for (int i = 0; i < 5; i++) {
			ft1.push_back(i);
		}

		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "😎 ft  begin() : " << *ft1.begin() << std::endl;
		std::cout << std::endl;
		std::cout << "😎 ft  end() - 1 : " << *(ft1.end() - 1) << std::endl;
		std::cout << std::endl;
		std::cout << "😎 ft  rbegin() : " << *ft1.rbegin() << std::endl;
		std::cout << std::endl;
		std::cout << "😎 ft  rend() + 1 : " << *(ft1.rend() - 1) << std::endl;
		std::cout << std::endl;

		std::cout << "> begin 부터 end 까지 출력" << std::endl;
		print_vector(ft1);

	}
	std::cout << "----------------------- Capacity " << std::endl;
	{
		std::cout << "  [ size test ]" << std::endl;
		std::cout << "> 빈 벡터 생성" << std::endl;
		TESTED_NAMESPACE::vector<int> ft1;

		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> 숫자 100 이 4개 들어간 벡터 생성" << std::endl;
		TESTED_NAMESPACE::vector<int> ft2(4, 100);

		std::cout << "😎 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ max_size test ]" << std::endl;
		std::cout << "😎 ft  : " << ft2.max_size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ resize test - (2) ]" << std::endl;
		// 나중에 추가 필요
		std::cout << "> 2칸으로 resize" << std::endl;
		ft2.resize(2);
		std::cout << "😎 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 10칸으로 resize, 42로 채우기" << std::endl;
		ft2.resize(10, 42);
		std::cout << "😎 ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		ft2.clear();
		std::cout << "> clear로 비움" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ empty test ]" << std::endl;

		std::cout << "> 빈배열의 경우" << std::endl;
		std::cout << "😎 ft  : " << ft2.empty() << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> 빈배열이 아닌 경우" << std::endl;
		ft2.push_back(1);
		std::cout << "😎 ft  : " << ft2.empty() << std::endl;
		print_vector(ft2);
		std::cout << std::endl;


		std::cout << "  [ reserve test ]" << std::endl;
		TESTED_NAMESPACE::vector<int> ft3(4, 5);
		std::cout << "> 5 가 4개 들어간 벡터"<< std::endl;
		print_vector(ft3);
		std::cout << std::endl;

		std::cout << "> 11으로 reserve"<< std::endl;
		ft3.reserve(11);
		print_vector(ft3);
		std::cout << std::endl;

		std::cout << "> 3으로 reserve (아무일도 일어나지 않음)"<< std::endl;
		ft3.reserve(3);
		print_vector(ft3);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Element access " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(1, 100);

		std::cout << "  [ operator[] test ]" << std::endl;
		std::cout << "😎 ft  : ";
		print_vector(ft1);
		std::cout << "ft[0]  : " << ft1[0] << std::endl;
		std::cout << std::endl;

		std::cout << "> push_back(12)" << std::endl;
		ft1.push_back(12);
		std::cout << std::endl;

		std::cout << "😎 ft  : ";
		print_vector(ft1);
		std::cout << "ft[1]  : " << ft1[1] << std::endl;
		std::cout << std::endl;

		std::cout << "  [ at test ]" << std::endl;
		std::cout << "😎 ft.at(1)  : " << ft1.at(1) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ front test ]" << std::endl;
		std::cout << "😎 ft.front()  : " << ft1.front() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ back test ]" << std::endl;
		std::cout << "😎 ft.back()  : " << ft1.back() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "----------------------- Modifiers " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 100);
		TESTED_NAMESPACE::vector<int>::iterator ft_iter;

		std::cout << "  [ assign test ]" << std::endl;
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> 2, 77 assign" << std::endl;
		ft1.assign(2, 77);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> 5, 42 assign" << std::endl;
		ft1.assign(5, 42);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> (begin() + 1, end() - 1) iterator assign" << std::endl;
		ft_iter = ft1.begin() + 1;
		ft1.assign(ft_iter, ft1.end() - 1);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ push_back test ]" << std::endl;
		std::cout << "> push_back(100)" << std::endl;
		ft1.push_back(100);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ pop_back test ]" << std::endl;
		std::cout << "> pop_back" << std::endl;
		ft1.pop_back();
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ insert test ]" << std::endl;
		std::cout << "> insert begin(), 1" << std::endl;
		ft1.insert(ft1.begin(), 1);
		std::cout << "😎 ft  ( size : " << ft1.size()  << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> insert begin() + 1, 2, 2" << std::endl;
		ft1.insert(ft1.begin() + 1, 2, 2);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> insert begin() + 3, iter(begin), iter(end)" << std::endl;
		std::cout << "> iter : [3, 3, 3]" << std::endl;
		TESTED_NAMESPACE::vector<int> add2(3, 3);
		ft_iter = add2.begin();
		ft1.insert(ft1.begin() + 3, ft_iter, add2.end());
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ erase test ]" << std::endl;
		std::cout << "> erase begin + 3" << std::endl;
		ft1.erase(ft1.begin() + 3);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> erase end() - 1" << std::endl;
		ft1.erase(ft1.end() - 1);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> erase first(begin), last(begin + 3)" << std::endl;
		ft1.erase(ft1.begin(), ft1.begin() + 3);
		std::cout << "😎 ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
	}
		std::cout << "  [ swap test ]" << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 1);
		TESTED_NAMESPACE::vector<int> ft2(3, 99);

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 1.swap(2)" << std::endl;
		ft1.swap(ft2);

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ clear test ]" << std::endl;
		std::cout << "> clear()" << std::endl;

		ft1.clear();
		ft2.clear();
		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Allocator " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft;

		std::cout << "> get_allocator" << std::endl;
		std::cout << "> allocate(5)" << std::endl;
		int *p2 = ft.get_allocator().allocate(5);

		std::cout << "> construct(0 ~ 4)" << std::endl;
		for (int i = 0; i < 5; i++) {
			ft.get_allocator().construct(&p2[i], i);
		}

		std::cout << "😎 ft  : ";
		for (int i = 0; i < 5; i++)
			std::cout << p2[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "----------------------- Non-member function " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(5, 5);
		TESTED_NAMESPACE::vector<int> ft2(5, 5);
		
		std::cout << "  [ operator == test 1 ]" << std::endl;
		
		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  == ft2  : " << (ft1 == ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator == test 2 ]" << std::endl;

		ft1.push_back(1);

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  == ft2  : " << (ft1 == ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator != test 1 ]" << std::endl;

		ft1.pop_back();

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  != ft2  : " << (ft1 != ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator != test 2 ]" << std::endl;

		ft1.push_back(1);

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  != ft2  : " << (ft1 != ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator < test 1 ]" << std::endl;

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  < ft2  : " << (ft1 < ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator < test 2 ]" << std::endl;
		TESTED_NAMESPACE::vector<std::string> ft3(3, "a");
		TESTED_NAMESPACE::vector<std::string> ft4(2, "a");

		ft4.push_back("b");

		std::cout << "😎 ft1  : ";
		print_vector(ft3);
		std::cout << "😎 ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "😎 ft1  < ft2  : " << (ft3 < ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator <= test 1 ]" << std::endl;

		std::cout << "😎 ft1  : ";
		print_vector(ft3);
		std::cout << "😎 ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "😎 ft1  <= ft2  : " << (ft3 <= ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator <= test 2 ]" << std::endl;

		ft1.pop_back();

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  <= ft2  : " << (ft1 <= ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator > test 1 ]" << std::endl;

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  > ft2  : " << (ft1 > ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator > test 2 ]" << std::endl;

		std::cout << "😎 ft1  : ";
		print_vector(ft3);
		std::cout << "😎 ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "😎 ft1  > ft2  : " << (ft3 > ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator >= test 1 ]" << std::endl;

		std::cout << "😎 ft1  : ";
		print_vector(ft3);
		std::cout << "😎 ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "😎 ft1  >= ft2  : " << (ft3 >= ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator >= test 2 ]" << std::endl;

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "😎 ft1  >= ft2  : " << (ft1 >= ft2) << std::endl;
		std::cout << std::endl;

	}

	std::cout << "  [ swap test ]" << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 1);
		TESTED_NAMESPACE::vector<int> ft2(3, 99);

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 1.swap(2)" << std::endl;
		ft1.swap(ft2);

		std::cout << "😎 ft1  : ";
		print_vector(ft1);
		std::cout << "😎 ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;
	}
    end = clock();
    std::cout << "result : " << (double)(end - start) << std::endl;
}
