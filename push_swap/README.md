# Push_swap

## Production period.
- (21.04.09 ~ 21.08.02)

## Description
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.
To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.



### Keywords
- Sorting algorithms
- Battery concept and handling elements
- Algorithm implementation
### Skills
- Unix
- Rigor
- Imperative programming
- Algorithms & AI

## Goals
To write a sorting algorithm is always a very important step in a coder’s life, because it
is often the first encounter with the concept of complexity.
Sorting algorithms, and their complexities are part of the classic questions discussed
during job interviews. It’s probably a good time to look at these concepts because you’ll
have to face them at one point.
The learning objectives of this project are rigor, use of C and use of basic algorithms.
Especially looking at the complexity of these basic algorithms.
Sorting values is simple. To sort them the fastest way possible is less simple, especially
because from one integers configuration to another, the most efficient sorting algorithm
can differ.

## Mandatory
### Rules
- The game is composed of 2 stacks named a and b.
- To start with:
  - the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - b is empty
- The goal is to sort in ascending order numbers into stack a.
- To do this you have the following operations at your disposal:

### Commands
- __sa__ : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- __sb__ : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- __ss__ : sa and sb at the same time.
- __pa__ : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- __pb__ : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- __ra__ : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- __rb__ : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- __rr__ : ra and rb at the same time.
- __rra__ : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- __rrb__ : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- __rrr__ : rra and rrb at the same time.

## Score
[![sjin's 42Project Score](https://badge42.herokuapp.com/api/project/sjin/push_swap)]
