# Makefile for bit-exercises

CC = g++
FLAGS = -std=c++11 -Wall -Werror

all : ordinals title_case guest_book parsum collision hungry_cat

ordinals : ordinals.o helpers.o
	$(CC) $(FLAGS) -o ordinals ordinals.o helpers.o
ordinals.o : ordinals.cpp helpers.h
	$(CC) $(FLAGS) -c ordinals.cpp

title_case : title_case.o helpers.o
	$(CC) $(FLAGS) -o title_case title_case.o helpers.o
title_case.o : title_case.cpp helpers.h
	$(CC) $(FLAGS) -c title_case.cpp

guest_book : guest_book.o helpers.o
	$(CC) $(FLAGS) -o guest_book guest_book.o helpers.o
guest_book.o : guest_book.cpp helpers.h
	$(CC) $(FLAGS) -c guest_book.cpp

parsum : parsum.o
	$(CC) $(FLAGS) -o parsum parsum.o
parsum.o : parsum.cpp
	$(CC) $(FLAGS) -c parsum.cpp

collision : collision.o helpers.o
	$(CC) $(FLAGS) -o collision collision.o helpers.o
collision.o : collision.cpp helpers.h
	$(CC) $(FLAGS) -c collision.cpp

hungry_cat : hungry_cat.o
	$(CC) $(FLAGS) -o hungry_cat hungry_cat.o
hungry_cat.o : hungry_cat.cpp
	$(CC) $(FLAGS) -c hungry_cat.cpp

framed : framed.o helpers.o
	$(CC) $(FLAGS) -o framed framed.o helpers.o
framed.o : framed.cpp
	$(CC) $(FLAGS) -c framed.cpp

six_degrees : six_degrees.o helpers.o
	$(CC) $(FLAGS) -o six_degrees six_degrees.o helpers.o
six_degrees.o : six_degrees.cpp helpers.h
	$(CC) $(FLAGS) -c six_degrees.cpp

helpers.o : helpers.cpp helpers.h
	$(CC) $(FLAGS) -c helpers.cpp

# For local testing
test : test.o helpers.o
	$(CC) $(FLAGS) -o test test.o helpers.o
test.o : test.cpp helpers.h
	$(CC) $(FLAGS) -c test.cpp