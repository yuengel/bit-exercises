# cs50-contest-2017
Solutions to [CS50x Coding Contest 2017](https://www.hackerrank.com/cs50x-2017) problems, written in C++.

## The problems

* **Ordinary Ordinals**, solved in ordinals.cpp
  
  > Write a program that, given a string S of space-separated words via standard input, finds the position of the word "cat".
  >
  > If a cat is found, the program should print "The cat is the n item in the box", where n represents an ordinal number. If you find     > another cat, do nothing. If no cat is found, the program should print "No cat yet". If an empty string is passed to your program, it   > should print "There is no box" and exit.
  
* **Title Case**, solved in title_case.cpp

  > Write a program that, given a single string S terminated by a newline character, will capitalize the first letter of each word         > except the words "the", "of", "and", and "but", unless any of those four words is also the first or last word of S.
  
* **Be Our Guest**, solved in guest_book.cpp

  > Write a program for a hotel manager that, given via standard input a two-dimensional map of hotel rooms and whether they are vacant   > or occupied, takes in a value representing the number of rooms that a new group is trying to book.
  >
  > If there is space in the hotel for all of the rooms to be consecutive, your program should output 1. If there is not space for all     > of the rooms to be next to one another, your program should output 0.
  
* **Parsum**, solved in parsum.cpp

  > Write a program that, given a string S representing an algebraic sum of integers, parses it and finds its value.
  
* **AABB Collision Detection**, solved in collision.cpp

  > Write a program that reads values describing two AABBs from standard input and prints the area of their overlapping region or 0.00     > if they do not overlap.
  
* **Cats Eat Fish**, solved in hungry_cat.cpp

  > Write a program, that given the number of fish F the cat starts with, the number of days D the cat plans to eat fish, and how many     > fish the cat will eat per day Ei, returns the day that our poor kitty will run out of fish.
  
* **Framed**, solved in framed.cpp

  > Write a program that, given a string S, outputs a pretty-printed version of S inside of a boxed frame made up of # characters, with   > each word on its own line.
  
* **Six Degrees of Bill Gates**, solved in six_degrees.cpp

  > Write a program that, given a number of people N as an integer, an N_x_N matrix of integers A, where A[0,3] = 1 means that people 0   > and 3 have a connection and A[5,2] = 0 means that people 2 and 5 do not have a connection, and two integers, X and Y representing     > the two people to check, print via standard output the number that is the smallest number of connections to have the two people       > connected. If no connection is possible, print -1.
  
* **When In Rome**, solved in roman_numeral.cpp

  > Write a program that, given a Roman numeral as a string R, prints via standard output the integer value of that numeral.
  
* **Feeding Garfield**, solved in garfield.cpp

  > Jon recently noticed that Garfield is always hungry. He decides to go on a grocery run and comes back with a variety of food items.   > Each food item satisfies Garfield's hunger by si and gives Garfield hi happiness.
  >
  > We shall represent each food item as a tuple (si, hi). Garfield's goal is to maximize his overall happiness H by eating the food  >   > items given that he starts at a given hunger level L. Note that by eating a particular food item, he increases his happiness by hi     > and decreases his current hunger level by si.
  >
  > Garfield will also incur a -20 happiness for every unit he gets overfed (i.e. sum of the si - L) and will incur a -10 happiness for   > each unit of hunger that isn't satisfied (i.e. L - sum of the si).
  >
  > Write a program that, given Garfield's current hunger level L and a list of food items si, hi, outputs the maximum happiness H that   > Garfield can achieve.
