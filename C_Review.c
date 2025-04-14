Data Types:
	1. basic types : integer and floating point
	2. enumerated types: define variables that can only assign certain discrete integer values
	   throughout the program.
	3. The type void
	4. derived types: pointer types/array types/ structure types/union types and function types	
			array and structure types are reffered to as aggregate types
	
	VOID TYPE - 
		3 situations: functions return as void, function arguments of void or pointers to void
				pointers to void:
					a pointer type of void reperesents the address of an object, but not its type
					eg void *malloc(size_t size); returns a pointer to void which can be casted to
												  any data type


LVALUE AND RVALUE:
  lvalue refers to memory location, can be on left or right of assignment
  rvalue refers to data value - on right of assignment ALWAYS

 CONSTANTS AND LITERALS
 	constants are fixed values that can't be altered during program run
	treated just like variables, but values can't be modigfied

	-use preprocessor  eg: #defin MAX_SIZE 50     (no equals or ;)
	-use const keyword eg: const int MAX_SIZE = 5;

	  ****in both cases, common to use all caps***

STORAGE CLASSES
   auto
   register - stored in a register instead of RAM (maybe!) only used for quick access variables 
   			  like counters 
   static - keep variable value through life of program.  When used in global variables restricts 
            scope to current file only
   extern - use global variables from another file

OPERATORS
	arithmetic
	releational
	logical
	bitwise
	assignment
	misc - sizeof, &, *, ?:

INITIALIZING GLOBAL AND LOCAL VARIABLES
	local variables must be initialized by hand
	global variables are initialized by the syetem when declared:
		int 0
		char '\0'
		float 0
		double 0
		pointer NULL

ARRAYS
	-data structure that stores fixed-size sequential sequence of elements
	 of the same type (collection of variables of same type)
	-occupies contiguous memory locations

	Example program to show declaration, assignemnt and accessing arrays

	___________________________________________________________________________

	#include<stdio.h>

	int main(void)
	{
		int n[10];
		int i, j;
        /* assign value to each element starting with 100 and increasing
		   by 1 for each element*/
		for (i = 0; i <10; i++)
			n[i] = i + 100;
		/* output each array element's value'*/
		for (j = 0; j < 10; j++)
			printf("Element[%d] is %d\n", j, n[j]);
		return (0);
    ______________________________________________________________________________

	rewrite with one loop:

	______________________________________________________________________________

	#include<stdio.h>

	int main(void)
	{
		int n[10];
		int i;

		for(i=0; i <10; i++)
		}
			n[i] = i + 100;
			printf("Element[%d] is %d\n", i, n[i]);
		}
		return (0);
	}

	________________________________________________________________________________

PASSING ARRAYS TO FUNCTIONS
	3 Ways
		1. formal parameter as pointer:
			void myFunction(int *param)
			{
				/*code here*/
			}	

		2. formal parameter as sized array:
			void myFunction(int param[10])
			{
				/*code here*/
			}
		3. formal parametetr as an unsized array:
			void my Function(int param[])
			{
				/*code here*/
			}

	Example 
	___________________________________________________________________________________

	#include<stdio.h>

	double getAverage(int arr[], int size);

	int main(void)
	{
    	int balance[] = {1000, 2, 3, 17, 50};
    	double avg;

    	/*Pass a pointer to the array*/
    	avg = getAverage(balance, 5);

    	/*output the returned value*/
    	printf("The average of balance is %.2f\n", avg);
	}
	double getAverage(int arr[], int size)
	{
    	int i;
    	double avg, sum;

    	for (i = 0; i < size; i++)
        	sum += arr[i];
    	avg = sum / size;
    	return(avg);
	}
   __________________________________________________________________________________________

RETURN AN ARRAY FROM A FUNCTION

	cannot return an entire array, but can retuen a pointer to an array by specifing
	the array's name without an index
		int * myFunction()
		{
			/*body of function*/
		}
	C does not advocate to return the addrss of alocal variable to outside of the function,
	so you have to define the local variable as static

	EXAMPLE -= Generate 10 random numbers
	_________________________________________________________________________________________

	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>


	/*A program to demonstrate return an array from a function*/

	int * getRandom(void);

	int main(void)
	{
    	int *p;  /*a pointer to an int*/
    	int i;

    	p = getRandom();
    	for (i = 0; i < 10; i++)
        	printf("*(p + %d) : %d\n", i, *(p + i));

    	return (0);
	}

	int * getRandom(void)
	{
    	static int r[10];
    	int i;

    	/*set the seed*/
    	srand((unsigned)time( NULL ));
    	for(i = 0; i < 10; i++)
    	{
        	r[i] = rand();
        	printf("r[%d] = %d\n", i, r[i]);
    	}
    	return (r);
	}
	____________________________________________________________________________________

POINTER TO AN ARRAY

	an array name is a constant pointer to the first element in the array
		eg: double balance[50];
		    balance is a pointer to &balance[0];
		eg: assaign p to balance[0]:
			__________________________________________
			double *p;
			double balance[10];

			p = balance;
			__________________________________________

		Its legal to use array names as constant pointers and vice versa so you can access 
		elements:
			*(balance + 2) to acces element at balance[2] or
			*(p + 2) after p has been assaigned to balance

    Example using pointer to array and array name to display element values:
	________________________________________________________________________________________

	#include<stdio.h>

	int main(void)
	{
    	double balance[] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    	double *p;
    	int i;

    	p = balance;

    	/*output each array element's value*/

    	printf("Array values using pointer:\n");
    	for(i = 0; i < 5; i++)
        	printf("*(p + %d) : %.2f\n", i, *(p + i));
    	printf("Array values using array name as address:\n");
    	for(i = 0; i < 5; i++)
        	printf("*(balance + %d) : %.2f\n", i, *(balance + i));
    	return (0);
	}
	_________________________________________________________________________________________

POINTERS

	Declaration - type *var-name;
	              int *int_ptr;

	NULL POINTERS - int *ptr = NULL;
		value is defined as 0, nothing can point to memory location 0 as that is 
		reserved for the OS.  Null pointer is used to signal the pointer points to nothing

		to check for a NULL pointer, you can use if:
			if(ptr)  /*successful if ptr is not NULL*/
			if(!ptr) /*successful if ptr is NULL*/
	
	_________________________________________________________________________________
	CONCEPT                       |  DESCRIPTION
	______________________________|___________________________________________________
                                  |
	POINTER ARITHMATIC            |four operators can be used:
								  |++, --, +, -
	__________________________________________________________________________________	
	             				  |
	ARRAY OF POINTERS			  |you can define arrays to hold a
								  |number of pointers.
    __________________________________________________________________________________
                                  |
	POINTER TO A POINTER          |C allows you to have a pointer on a 
								  |pointer and so on
                                  |
    __________________________________________________________________________________
                                  |
	PASSING POINTERS TO FUNCTIONS |passing an argument by reference (or address)
								  |enables the passed argument to be changed
								  |by the called function
	__________________________________________________________________________________
								  |
	RETURN POINTER FROM FUNCTIONS |C allows a function to return a pointer to 
								  |the local variable, static variable and
								  |dynamically allocated memory
    __________________________________________________________________________________


	POINTER ARITHMATIC
		four operators: ++, --, +, -
		ptr++ or (ptr + 1) move next memory location
		   eg: int ptr address at 1000 ptr++ will go to 1004
		       char ptr address at 1000 ptr++ will go to 1001
		array cannot be incremented this way, array name is a const pointer
		 	to array[0], must use pointer

	POINTER COMPARISONS
		compared by using relational operators: ==, !=, <, <=, >, >=

								  |
    Example: incrementing ponter so long as it hasn't reached last address in array
	_________________________________________________________________________________

	#include<stdio.h>

	/*Increments the variable pointer so long as the address to
  	which it points is either less than or equal to the address
  	of the last element of the array which is &var[MAX -1]*/

	const int MAX = 3;

	int main(void)
	{
    	int var[] = {10, 100, 200};
    	int i, *ptr;
    	ptr = var;
    	i=0;

    	while (ptr <= &var[MAX -1])
    	{
        	printf("Address of var[%d] = %p\n", i, ptr);
        	printf("Value of var[%d] = %d\n", i, *ptr);
        	ptr++;
        	i++;
    	}
	}
	_____________________________________________________________________________________


ARRAY OF POINTERS

	int *ptr[MAX];

	EXAMPLE - store a list of strings
	_______________________________________________________________________________________

	include<stdio.h>

	const int MAX = 4;

	int main(void)
	{
    	char *names[] = {
        	"Mark Hayes",
        	"Stephen Hayes",
        	"Arthur Hayes",
        	"Sally Hayes"
    	};
    	int i = 0;

    	for(i = 0; i < MAX; i++)
        	printf("Value of names[%d] = %s\n", i, names[i]);
    	return (0);
	}
	________________________________________________________________________________________


POINTER to POINTER
	chain of pointers or multiple indirection

	PTR  ----> PTR  -----> VARIABLE
	address   address      value

	pointer to a variable is being pointed at by another pointer

    to derefernce the value from the first pointer **
	example:
	_______________________________________________________________________________________

	#include<stdio.h>

	int main(void)
	{
		int var, *ptr, **pptr;
		var = 3000;
		ptr = &var /*take the address of var*/
		pptr = &ptr /*take the address of ptr*/

		printf("Value of var = %d\n", var);
		printf("Value available at *ptr = %d\n", *ptr);
		printf("Value available at **pptr = %d\n", **pptr);
		return (0);
	}
    _______________________________________________________________________________________


PASSING POINTERS TO FUNCTIONS
	
	Can pass a function to a pointer - declare parameter as a pointer type

	Example: Pass an Unsigned long pointer to a function and change the value in the 
	calling functipon
	_______________________________________________________________________________________

	#include<stdio.h>
	#include<time.h>

	void getSeconds(unsigned long *pair);

	int main(void)
	{
    	unsigned long sec;

    	getSeconds(&sec);
    	printf("Number of seconds: %ld\n", sec);
    	return (0);
	}

	void getSeconds(unsigned long *par)
	{
    	/*Get the current number of seconds*/
    	*par = time(NULL);
    	return;
	}
	________________________________________________________________________________________


STRINGS

	a string is an array of characters terminated by '\0'.
	char arr[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char arr[] = "Hello";
	char *arr = "Hello"

	STRING FUNCTIONS: <string.h>
		
		strcpy(s1, s2);
		strcat(s1, s2);
		strlen(s1);
		strcmp(s1,s2);
			returns 0 if s1 == s2, <0 if s1<s2 and >0 if s1>s2
		strchr(s1, ch);
			returns a pointer to the first occurance of ch in s1
		strstr(s1,s2)
			returns a pointer to the first occurance of s2 in s1

	Each individual element of a char array is an lvalue which an individual
	 character may be assigned, but a chat pointer is also an lvalue to which 
	 an entire string may be assigned after that pointer has been declared 

STRUCTURES
	-data type that allows one to store data of different types
	-variables within structures are know as members
	-will typically declare before main()
	eg: struct Books 

		{
			char title[50];
			char author[50];
			char subject[100];
			int book_id;
		}book;   /*optional tag*/
	
	Accessing Structure Members
		member access operator(.)
	
	Example: Create and print Book struct
	_____________________________________________________________________________________

	#include<stdio.h>
	#include<string.h>

	struct Books
	{
    	char title[50];
    	char author[50];
    	char subject[100];
    	int book_id;
	};

	int main(void)
	{
    	struct Books Book1;
    	struct Books Book2;

    	/*book1 specification*/
    	strcpy(Book1.title, "C Programming");
    	strcpy(Book1.author, "Nuha Ali");
    	strcpy(Book1.subject, "C Programming Tutorial");
    	Book1.book_id = 6495407;

    	/*Book2 specification*/
    	strcpy(Book1.title, "Telecom Billing");
    	strcpy(Book1.author, "Zara Ali");
    	strcpy(Book1.subject, "Billing Tutorial");
    	Book1.book_id = 6495700;

    	/*Print Book1 Info*/
    	printf("Book 1 title: %s\n", Book1.title);
    	printf("Book 1 author: %s\n", Book1.author);
    	printf("Book1 subject: %s\n", Book1.subject);
    	printf("Book1 ID: %d\n", Book1.book_id);
    	return(0);
	}

	_______________________________________________________________________________________

	Pointers to Structures
		define:
			struct Books *struct_pointer; 
		store address
			struct_pointer = &Book1;
		access members of a structure using ptr (->)
			struct_pointer ->title
	Example - re-write Book code above using pointers to structures:
	_______________________________________________________________________________________

	#include<stdio.h>
	#include<string.h>

	struct Books
	{
    	char title[50];
    	char author[50];
    	char subject[100];
    	int book_id;
	};
	void printBook(struct Books *book);

	int main(void)
	{
    	struct Books Book1;
    	struct Books Book2;

    	strcpy(Book1.title, "C Programming");
    	strcpy(Book1.author, "Nuha Ali");
    	strcpy(Book1.author, "Nuhu Ali");
    	strcpy(Book1.subject, "C Programming Tutorial");
    	Book1.book_id = 6495407;
    	printBook (&Book1);
	}
	void printBook(struct Books *book)
	{
    	printf("Book title: %s\n", book->title);
    	printf("Book author: %s\n", book->author);
    	printf("Book subject: %s\n", book->subject);
    	printf("Book book_id: %d\n", book->book_id);
	}
	_________________________________________________________________________________________
    

	-new structure variables can be declared using the name of an existing  structure
	 and that variable will inherit the original member properties

	 Example:
	_____________________________________________________________________________________

DATA STRUCTURES AND ALGORITHMS

	Algorithms: input and output defines preccisely
				each step should be clear and unambiguous
				psuedocode

				Example: Algorithm to check if number is prime
				step1: Start
				step2: declare vaariables n, i, flag
				step3: initialize variables: flag - 1, i -2
				step4: read n from user
				step5: repeat the steps until i=(n/2)
				   step5-1: if remainder of n/i equals 0
				   				flag 0
								go to step 6
					step5-2: i + 1
				step6: if flag = 0
						display n is not prime
					   else
						 display n is prime
			    step7: stop

	Data Structure and Types
		Linear and Nonlinear:
		Linear data structures:
			arranged in sequence one after another - easy to implement
			as complexity increasees, linear data may not be best choice due
			to operational complexities
			1. Array Data Structure
				stored in contigous memory and all data is the same type
			2. Stack Data Structure
				LIFO
			3. Que data structure
				FIFO
			4. Linked List
				data elements are connected through a series of nodes
				each node contains the data items and addresses to the next
				nodes
		Non-Linear Data Structures
			not in any sequence but in hierarchical manner where one element will be
			connected to one or more elements
			1. Graph Data Structures
				each node is called a vertex and each vertex is connected to other
				vertices through edges
			2. Tree Data Structures
				similiar to graph, but only one edge between two vertices
				eg: binary tree, binary search tree avl tree, b-tree, B+ tree
					red-black tree


		___________________________________________________________________________
		LINEAR DATA STRUCTURES        	  |NON LINEAR DATA STRUCTURES
		___________________________________________________________________________
		                                  |
		data items are arranged in        |non-sequential order
		sequential order				  |
		___________________________________________________________________________
										  |
		items are all present on          |data items are on different layers
		a single layer					  |
		___________________________________________________________________________
		                                  |
		It can be traversed on a single   |requires multiple runs
		run. 							  |
		___________________________________________________________________________
		                                  |
		Memory utilization is not         |Different structures utilize memory
		efficient						  |in different efficient ways
		___________________________________________________________________________
		                                  |
		Time Compexity increases with     |Time complexity remains the same
		data size                    	  |
		___________________________________________________________________________
		                                  |
		EG Array,stack, que				  |tree graph map
		                                  |
		___________________________________________________________________________

	   Two most valuable resoiurces for a program:
	   		Time
			Memory
		 time to run code = number instruction * time to exec each instruction

		 linearly scalable alogrithms vs constant time algorithms

         KMP String matching algorithm
		 https://ics.uci.edu/~eppstein/161/960227.html

	 ASYMPTOTIC ANALYSIS 

         asymptotic analysis - 
	  	 The study of change in performance of the algorithm with the change in the 
		 order of the input size

		 asymptotic notations - 
		 mathematical notations used to describe the running time of an algorithm
		 when the input tends towards a particular value or a limiting value.
		     eg: bubble sort when input is already sorted, the time taken by
			     the algorithm is linear (best case)

				 but when the input array is in reverse condition, the algorithm
				 takes the maximum time (quadratic) to sort the elements (worse case)

				 when the input array is neither sorted nor in reverse order, then
				 it tales average time

				 These durations are noted using asymptotic notations
		  	1. Big-O notation
				worst case complexity of an algorithm
				represents the upper bound of running time for an algorithm
				f(n) = O(g(n))

					function f(n) belongs to the set O(g(n)) if there exists
					a positive constant c such that it lies between 0 and cg(n)
					for sufficiently large n
					for any value of n, the running time of algorithm does not cross
                    the time provided by O(g(n))
			2. Omega notation
				best case complexity algorithm - represents the lower bound of the 
				running time of an algorithm
				f(n) = Ω(g(n))
					function f(n) belongs to the set Ω(g(n)) if there exists positive
					constant c such that it lies above cg(n), for sufficiently
					large n
					for any value of n, the minimum time required by the algorithm
					is given by Omega Ω(g(n))
			3. Theta notation
				average case complexity - represents the upper and lower bound
				of the running time of an algorithm
				f(n) = Θ(g(n))
	 MASTER THEOREM
	 	used in divide and conquer algorithms

	 	T(n) = aT(n/b) + f(n)

		where:
		  n = size of input
		  a = number of sub-problems in the recursion
		  n/b = size of each each subproblem. All subproblems are assumed
		        to have the same size
		 f(n) = cost of the work done outside the recursive call,which includes
		        the cost of dividing the problem and the cost of merging the soliutions	
					
		        		  
		  	

																																										
																																										 
