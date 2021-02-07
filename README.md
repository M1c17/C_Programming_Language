# C_Programming_Language

Exercises and Solutions for The C programming Language, 2nd Edition
[The C Programming Language, Second Edition
by Brian W. Kernighan and Dennis M. Ritchie.
Prentice Hall, Inc., 1988.](https://github.com/M1c17/C_Programming_Language/blob/main/The%20C%20Programming%20Language%20-%202nd%20Edition%20-%20Ritchie%20Kernighan.pdf)

How to run C programs?
Check this links:
1.[Compiling C files with gcc, step by step](https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052)
2.[How to Run C-Program in Command Prompt](https://randerson112358.medium.com/how-to-run-c-program-in-command-prompt-e435186cd162)
3.[Compiling C code from the terminal](https://www.youtube.com/watch?v=FGSlg8L5kf0)

## Chapter 1:
Ex_1.2 = How to use printf()
Ex_1.3 = print a Conversion Table fahr, celsius
Ex_1.4 = print a Conversion Table celsius, fahr
Ex_1.5 = print a Conversion Table celsius, fahr in reverse order
Ex_1.6 = print getchar()
Ex_1.7 = print value EOF
Ex_1.8 = program to count blanks, tabs and newlines
Ex_1.9 = replacing each string of one or more blanks by single blank
Ex_1.10 = makes tabs and backspaces visible in an unambiguos way
Ex_1.11 = Word_count program
Ex_1.12 = Write a program that prints its input one word per line
Ex_1.13 = Write a program to print a histogram of the lengths of words its input
Ex_1.14 = Write a program to print a histogram of the frequencies of the diferent charaters
Ex_1.15 = Write a program to convert fahr to celsius
Ex_1.16 = print the longest input
Ex_1.17 = print all input line that are longer to 80
Ex_1.18 = Write a program to remove trailing blanks and to delete enterely blanks line
Ex_1.19 = Reads a line of input at a time, reversed it and print the reversed line
Ex_1.20 = Write a program detab that replaces tabs in the input with the proper number of blanks
Ex_1.21 = Write program entab that replace every time position reach a multiple of TABINC with '\t'
Ex_1.22 = Write a program to "fold" long input lines
Ex_1.23 = Write a program to remove all comments from a C program
Ex_1.24 = Write a program to check a C program for syntax errors

## Chapter 2:
Ex_2.1 = Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned
Ex_2.2 = Write a for loop without using && or ||
Ex_2.3 = Write the function htoi(s)
Ex_2.4 = Write a program that delete every charac in s1 that matches every char in s2
Ex_2.5 = Write the function any => returns first location in the str s1 where any char from the st s2 occurs
Ex_2.6 = Write a function setbits(x, p, n, y)
Ex_2.7 = Write a function invert_bits(x, p, n, y)
Ex_2.8 = Write a function rightrot(x, n)
Ex_2.9 = Write a function count_bit(unsigned int x)
Ex_2.10 = Rewrite the function lower, which convert upper to lower, w/ a conditional expression instead of if-else

## Chapter 3:
Ex_3.1 = Binary search. Write a version with only one test inside the loop
Ex_3.2 = Write a function escape(s,t) => converts character like tab and new line in \t, \n
Ex_3.3 = Write a function expand(s1 s2) => expand short hand notation
Ex_3.4 = Rewrite our version of itoa to handle the largest negative number
Ex_3.5 = Write the function itob(n,s,b)
Ex_3.6 = Write a function of itoa that accept three arguments instead of two

## Chapter 4:
Ex_4.1 = Write the function strindex that return the pos in the str s where str t begins
Ex_4.2 = Extend atof to handle scientific notation of the form 123.456e-6
Ex_4.3 = Reverse Polish Notation Calculator
Ex_4.4 = Add commands elements of the stack for reverse polish notation calculator
Ex_4.5 = Add access to library functions like sin, exp, and pow <math.h>
Ex_4.6 = Add commands for handling variables. (26 single letter names)
Ex_4.7 = Write a routine ungets(s) that will push back an entire string onto the input
Ex_4.8 = Suppose that there will never be more than one character of pushback.Modify getch and ungetch accordingly
Ex_4.9 = Our getch and ungetch do not handle a pushed back EOF correctly
Ex_4.10 = Revise the Calculator program to use the getline instead of getch and ungetch
Ex_4.11 = modify getop so that it does not need to use ungetch: Hint: static int lastc
Ex_4.12 = Write itoa in recursive version
Ex_4.13 = Write a recursive version of the function reverse(s)
Ex_4.14 = Define a macro swap that interchanges two arguments of type t

## Chapter 5:
Ex_5.1 = getint : get next integer from input into *pn 
Ex_5.2 = write the function getfloat
Ex_5.3 = Write a pointer version of the function strcat
Ex_5.4 = strend returns 1 if string t occurs at the end of the string s
Ex_5.5 = Write strcpy(s, t, n) copies at most n characters of t to s
Ex_5.6 = getline: return len and store the input in array s. pointer version
Ex_5.7 = Readlines using array
Ex_5.8 = There is no checking error in day_of_year or month_of_day remedy that error
Ex_5.9 = Rewrite the programs day_of_year and month_day with pointers instead of indexes
Ex_5.10 = Write the program expr, which evaluate a polish reverse expression from the command line
Ex_5.11 = entab and detab which accepts arguments
Ex_5.12 = entab -m + which accepts arguments
Ex_5.13 = Write the program tail, which prints the last n lines of its input.
Ex_5.14 = Modify the sort program to handle a -r flag, which indicates sorting in reverse
Ex_5.15 = fold upper and lower case together¶
Ex_5.16 = Add -d makes comparison on letters, numbers, blanks
Ex_5.17 = Sorting with options
Ex_5.18 = Program that convert from valid C to word description
Ex_5.19 = Modify undcl so that it does not add redundant parentheses 
Ex_5.20 = Expand dcl to handle declarations with funcitons arguments

## Chapter 6:
Ex_6.1 = getword
Ex_6.2 = Identical Variables
Ex_6.3 = Write a cross-referencer
Ex_6.5 = undef: remove name and definition from table

## Chapter 7:
Ex_7.1 = upper case to lower or lower case to upper
Ex_7.2 = print non-graphic characters in octal or hexadecimal
Ex_7.3 = minprintf to handle facilities of printf
Ex_7.4 = private version of scanf
Ex_7.5 = Postfix calculator using scanf
Ex_7.6 = Compare Two files
Ex_7.7 = Pattern matching program with files
Ex_7.8 = Print Pages to Files
Ex_7.9 = Analyze implementations of isupper

## Chapter 8:
Ex_8.1 = Read and Write
Ex_8.2 = Buffered and Unbuffered getchar

