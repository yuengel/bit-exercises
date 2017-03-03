# Makefile for bit-exercises

CC = g++
FLAGS = -std=c++11 -Wall -Werror

all : ordinals title_case guest_book parsum

ordinals : ordinals.cpp
	$(CC) $(FLAGS) -o ordinals ordinals.cpp 
title_case : title_case.cpp
	$(CC) $(FLAGS) -o title_case title_case.cpp 
guest_book : guest_book.cpp
	$(CC) $(FLAGS) -o guest_book guest_book.cpp
parsum : parsum.cpp
	$(CC) $(FLAGS) -o parsum parsum.cpp
test : test.cpp helpers.cpp
	$(CC) $(FLAGS) -o test test.cpp helpers.cpp