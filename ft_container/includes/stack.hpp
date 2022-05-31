#ifndef __STACK_HPP__
# define __STACK_HPP__

# include <iostream>
# include <string>
# include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
	public:
		
		typedef T                 value_type;
		typedef Container         container_type;
		typedef size_t            size_type;

		
		explicit stack (const container_type& ctnr = container_type())
		: C_data(ctnr) { }
		virtual ~stack() {
		}
		bool empty() const { return (this->C_data.empty()); }
		size_type size() const { return (this->C_data.size()); }
		value_type& top() { return (this->C_data.back()); }
		const value_type& top() const { return (this->C_data.back()); }
		void push(const value_type& val) { this->C_data.push_back(val); }
		void pop() { this->C_data.pop_back(); }

		template<class Tn, class ContainerN>
		friend bool operator==(const ft::stack<Tn, ContainerN>& left,
							const ft::stack<Tn, ContainerN>& right);
		template<class Tn, class ContainerN>
		friend bool operator!=(const ft::stack<Tn, ContainerN>& left,
							const ft::stack<Tn, ContainerN>& right);
		template<class Tn, class ContainerN>
		friend bool operator<(const ft::stack<Tn, ContainerN>& left,
							const ft::stack<Tn, ContainerN>& right);
		template<class Tn, class ContainerN>
		friend bool operator<=(const ft::stack<Tn, ContainerN>& left,
							const ft::stack<Tn, ContainerN>& right);
		template<class Tn, class ContainerN>
		friend bool operator>(const ft::stack<Tn, ContainerN>& left,
							const ft::stack<Tn, ContainerN>& right);
		template<class Tn, class ContainerN>
		friend bool operator>=(const ft::stack<Tn, ContainerN>& left,
							const ft::stack<Tn, ContainerN>& right);
 
	protected:
		container_type C_data;  
	};

	template<class Tn, class ContainerN>
	bool operator==(const ft::stack<Tn, ContainerN>& left,
					const ft::stack<Tn, ContainerN>& right) 
	{ return (left.C_data == right.C_data); }
	template<class Tn, class ContainerN>
	bool operator!=(const ft::stack<Tn, ContainerN>& left,
					const ft::stack<Tn, ContainerN>& right) 
	{ return (left.C_data != right.C_data); }
	template<class Tn, class ContainerN>
	bool operator<(const ft::stack<Tn, ContainerN>& left,
					const ft::stack<Tn, ContainerN>& right) 
	{ return (left.C_data < right.C_data); }
	template<class Tn, class ContainerN>
	bool operator<=(const ft::stack<Tn, ContainerN>& left,
					const ft::stack<Tn, ContainerN>& right) 
	{ return (left.C_data <= right.C_data); }
	template<class Tn, class ContainerN>
	bool operator>(const ft::stack<Tn, ContainerN>& left,
					const ft::stack<Tn, ContainerN>& right) 
	{ return (left.C_data > right.C_data); }
	template<class Tn, class ContainerN>
	bool operator>=(const ft::stack<Tn, ContainerN>& left,
					const ft::stack<Tn, ContainerN>& right) 
	{ return (left.C_data >= right.C_data); }

}

#endif