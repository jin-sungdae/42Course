# get_next_line

## Production period.
- (20.12.28 ~ 21.01.14)

## Description
May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line. 
It is time to start working on this function, which will be essential for your future projects.

## Goals
This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming:
static variables.

## Mandatory
### Function name 
- get_next_line
### Prototype
- char *get_next_line(int fd);
### Turn in files 
- get_next_line.c, get_next_line_utils.c, get_next_line.h
### Parameters 
- File descriptor to read from
### Return value
- Read line: correct behavior
- NULL: nothing else to read or an error occurred
### External functs.
- read, malloc, free
### Description
- Write a function which returns a line read from a file descriptor

## Score
[![sjin's 42Project Score](https://badge42.herokuapp.com/api/project/sjin/get_next_line)]
