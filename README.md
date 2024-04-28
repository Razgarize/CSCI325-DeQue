# Deque Toolkit 

This program takes a templated Deque Toolkit and runs it through a number of stress tests that the user may select from. With a total of 15 different scenarios ready to run at the push of a button, this should be sufficient in demonstrating the capabilities of the Deque programming. 

# Implementation

- Our approach was to use the program to create a Deque system that worked similarly to a 2D array. For this iteration of the project, we used pointers to track the head and tail of the elements. 
- We tried multiple times to create using regular math to calculate to starting position of the first element, but we were having multiple issues regarding access and pushing and popping. So we used pointers instead as a pointer athematic is easier. 

So how we insert items is by using two pointers: 

- FrontPtr - Used to track which is the first element and insert new elements to the front by moving once over to the left.
- RearPtr  - Used to track which is the last element and insert new elements to the back by moving once over to the right.

An example would be inserting number/value 9 to the back:


```bash
F is for FrontPtr
R is for RearPtr

1. Current State of the Deque:
+---------------------+
| 0 0 0 0 1 2 3 4 5 0 |
|         ^       ^   |
|         F       R   |
+---------------------+

2. Moving the RearPtr to the right:

+---------------------+
| 0 0 0 0 1 2 3 4 5 0 |
|         ^         ^ |
|         F         R |
+---------------------+

3. Inserting the value 9 to the back:

+---------------------+
| 0 0 0 0 1 2 3 4 5 9 |
|         ^         ^ |
|         F         R |
+---------------------+
```

This works for the FrontPtr similarly, otherwise in the other direction.


When it comes to poping the Deque on the left or right, we would just delete the block and move the pointers to the start or end of the next Block, depending on which side is being popped.

Here is an example of a Front Block being popped:
```bash
F is for FrontPtr
R is for RearPtr

Original State:
+---------------------+
|                     |
|       Block[0]      | -------------> [0 0 0 7 1]
|                     |                       ^
+---------------------+                       F
|                     |
|       Block[1]      | -------------> [2 3 4 5 9]
|                     |                         ^
+---------------------+                         R
|                     |
|       Block[2]      | -------------> [0 0 0 0 0]
|                     |
+---------------------+
|                     |
|       Block[3]      | -------------> [0 0 0 0 0]
|                     |
+---------------------+
|        unused       |
+---------------------+

Popping the Front Block and moving the FrontPtr to the next block. 

+---------------------+
|        unused       |
+---------------------+                       
|                     |
|       Block[1]      | -------------> [2 3 4 5 9]
|                     |                 ^       ^
+---------------------+                 F       R
|                     |
|       Block[2]      | -------------> [0 0 0 0 0]
|                     |
+---------------------+
|       Block[3]      | -------------> [0 0 0 0 0]
+---------------------+
|        unused       |
+---------------------+



Moving the map blocks up! (This won't affect the address of the actual arrays)

+---------------------+                       
|                     |
|       Block[0]      | -------------> [2 3 4 5 9]
|                     |                 ^       ^
+---------------------+                 F       R
|                     |
|       Block[1]      | -------------> [0 0 0 0 0]
|                     |
+---------------------+
|       Block[2]      | -------------> [0 0 0 0 0]
+---------------------+
|        unused       |
+---------------------+
|        unused       |
+---------------------+

```



The reason for the move is to keep the Random Access simple. It is not efficient but is the only one we could make work.

For any new block that is inserted, we will insert a zero (0) into the entire new array.

# How To Use:
1. Clone the repository to your local machine. Open a terminal and run the following command:

```bash
git clone https://github.com/Razgarize/CSCI325-DeQue.git
```

2. Navigate to the project directory

```bash
cd CSCI325-DeQue
```

3. Compile the program using the provided Makefile:
```bash
make
```

4. Run the program (Should be just automatic test)
```bash
./bonus
```


# Work Divison 
Due to another round of schedule conflicts on either side and foundation-level bugs resulting in multiple drawing boards being cleared, James was the primary one implementing the meat and bones of the project - meanwhile, Seth handled the driver formatting and getting everything ready for user interaction.   

# Files
- Tempate_Deque.h : This includes the class definition and implementation.
- main_bonus.cpp : This is the test file
- Makefile : This allows easy compiling. 
- README.md : Readme file
- Old Tries : This has most of the attempts we have done. Proof that we worked on this for a while with not a lot of resutls. 

# Multiple attempts
We tried multiple times to complete this project with multiple ideas, including from lectures. We tried for days to create the mathematical version of the implementation, with complete failure. This has led us to the the pointers Implementation.

# Unfixed Bugs
- Random Access does have some issues. If there are some leading zeros on both ends, then you can't properly access it without doing some additional math. We tried for a few days to fix this issue, but we have run out of time as finals are right around the corner.
- Due to the leading and tailing zeros, we had it were the block just starts from the very beginning of the list. 



# Authors
- James Hart
- Seth Rivers