# Linked List Operations Program in C++
## 16520373 - Farrel Ahmad
### 29 May 2021
#
## Introduction
Notes : LL = Linked List

Linked List is a linear data structure that implements memory address as element's reference. An element in LL is often called a Node. A Node is a custom data type that contains values (for example, an integer) and next node's memory address (for example a pointer of Node). Each nodes are linked linearly towards another node. 

There are two types of LL, one is singly LL and the other one is doubly LL. The difference is singly LL only has one pointer to another node. While double LL has two pointer to another node. In singly LL you can only go to the next node, while in doubly LL you can go to the next node and previous node. For this code implementation, Singly Linked List is used.

![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)
Singly Linked List (Source : GeeksforGeeks)
#
![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png)
Doubly Linked List (Source : GeeksforGeeks)

LL is linear, unlike array that any elements can be accessed directly wherever it is, whether using index or element's memory address. Thus, to access certain node in LL, nodes should be accessed sequentially towards another node until it arrives in wanted node. 

The advantages of LL over array are dynamic memory size and ease of insertion and deletion. On the other hand, the disadvantages are random memory access is not allowed, extra memory space for pointers, and not cahce friendly.

Head, refers to the pointer variable that points to the first node. Head contains memory address of the first node.

## How to Compile The Program
1. Clone this repository to your local https://gitlab.com/dagozilla/academy/2021-internship1/16520373/day-2.git

```
git clone https://gitlab.com/dagozilla/academy/2021-internship1/16520373/day-2.git 
```

2. Change directory to the clone repository (day-2)
3. Change directory to 16520373
4. Make sure the directory contains main.cpp, by looking at ls command
5. run this command 
```
g++ main.cpp -o main
```
6. After that, open the compiled file called main by running this command
```
./main
```
## Running Program and Linked List Initializations
1. When the program succesfully runs, we can see the main menu
```
1. Initialize           2. Print List
3. Insert Node (Front)  4. Insert Node (End)
5. Remove First Node    6. Remove Last Node
7. Find Value           8. Find Max
9. Find Min             10. Size of List
11. Delete List         12. Copy List
13. Concatenate List    14. Inverse List
20. Quit
Insert Command: 
```
2. Enter the number command to use the LL operation

3. At first, LL1 and LL2 is empty. LL1 and LL2 first node are stored in head1 and head2  If we type 2 and enter, it will show this message.
```
LL1      : List is empty
LL1 Addr : 

LL2      : List is empty
LL2 Addr : 
```
4. We need to initialize first node by using no.1. We can also use Insert Node in no.3 or no.4 . It will automatically use initialize function when both or one of the LL1 is empty.

## Linked List Operations
1. After LL1 and LL2 are initialized, we can use Insert Node in no.3 and no.4 and then select to which LL to be added.

2. After that, we can see LL1 and LL2 nodes and it's memory address by using Print List in no.2. Here is the example
```
LL1      : 0 -> 1 -> 3 -> 3
LL1 Addr : (0x55a6c04ef6d0);(0x55a6c04ef6f0);(0x55a6c04ef710);(0x55a6c04ef730);

LL2      : 2 -> 4
LL2 Addr : (0x55a6c04ef750);(0x55a6c04ef770);
```
3. Use Remove Node in no.5 and no.6 to remove node. No.5 is to remove first node and No.6 is to remove last node.

4. By using Find Value in no.7, we can find whether there are nodes with certain value from the user input in LL1 or LL2. This operation will return all nodes memory address that has the value of the user input. For example we want to check value of 3 in LL1 that has been initialized previously

```
Insert Command: 7

1. LL1
2. LL2
Select Linked List : 1
Find value: 3

Value found in: 
(1) 0x55a6c04ef710
(2) 0x55a6c04ef730
```

5. Use No.8 to find maximum values of each LL and no.9 to find minimum values of each LL
```
Insert Command: 8

LL1 Max Value : 3
LL2 Max Value : 4
```

```
Insert Command: 9

LL1 Min Value : 0
LL2 Min Value : 2
```

6. Use Size of List (no.10) to check the size of each LL
```
Insert Command: 10

LL1 Size : 4
LL2 Size : 2
```

7. Use Delete List (no.11) to delete whole LL1 or whole LL2. For example, we want to delete whole LL2
```
Insert Command: 11

1. LL1
2. LL2
Select Linked List : 2
LL2 deleted
```
7. When we check Print List (no.2) LL2 will be empty
```
LL1      : 0 -> 1 -> 3 -> 3
LL1 Addr : (0x55a6c04ef6d0);(0x55a6c04ef6f0);(0x55a6c04ef710);(0x55a6c04ef730);

LL2      : List is empty
LL2 Addr : 
```

8. Use Copy List (No.12) to copy LL1 to LL2 or LL2 to LL1. If one of LL is empty, it will automatically be copied to the empty LL, but with different memory address. If both LL is empty, it will be unable to copy. If both LL is not empty, we can overwrite whether LL1 to LL2 or LL2 to LL1, but with different memory address. For example after we Delete LL2 and use Copy List, this is the output.
```
Insert Command: 12

LL1 has been copied to LL2

LL1      : 0 -> 1 -> 3 -> 3
LL1 Addr : (0x55a6c04ef6d0);(0x55a6c04ef6f0);(0x55a6c04ef710);(0x55a6c04ef730);

LL2      : 0 -> 1 -> 3 -> 3
LL2 Addr : (0x55a6c04ef750);(0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);
```

9. Use Concatenate List (No.13) to concatenate LL1 to LL2 or LL2 to LL1. There are two method options for this. We can either use without new allocated memory or with new allocated memory. For example, first method without new allocated memory and concatenate LL1 + LL2. This will link tail of LL1 to the head of LL2.
```
Select Method: 1

1. Concatenate LL1 + LL2
2. Concatenate LL2 + LL1
Select option : 1

LL1 + LL2 concatenated
Result in Print List
```

```
LL1      : 0 -> 1 -> 3 -> 3 -> 0 -> 1 -> 3 -> 3
LL1 Addr : (0x55a6c04ef6d0);(0x55a6c04ef6f0);(0x55a6c04ef710);(0x55a6c04ef730);(0x55a6c04ef750);(0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);

LL2      : 0 -> 1 -> 3 -> 3
LL2 Addr : (0x55a6c04ef750);(0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);
```
9. Because the first method will link either from LL1 to LL2 or LL2 to LL1, this will affect operations on both LL. For example by using previous concatenate, if we remove last node of LL2, then the last node of LL1 which has been concatenated from LL2 will also be deleted. This is because the memory address of that node will be deallocated. Thus the node will disappear from both LL1 and LL2.

9. We can also use second method Concatenate List but the result will be in a new allocated memory LL called LL3. For example concatenate LL1+LL2 -> LL3. This is basically copying each value in the order of LL and then put it in LL3 which has new allocated memory for each values.
```
Select Method: 2

1. Concatenate LL1 + LL2 into LL3
2. Concatenate LL2 + LL1 into LL3
Select option : 1

LL1      : 0 -> 1 -> 3 -> 3 -> 0 -> 1 -> 3 -> 3
LL1 Addr : (0x55a6c04ef6d0);(0x55a6c04ef6f0);(0x55a6c04ef710);(0x55a6c04ef730);(0x55a6c04ef750);(0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);

LL2      : 0 -> 1 -> 3 -> 3
LL2 Addr : (0x55a6c04ef750);(0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);

LL3      : 0 -> 1 -> 3 -> 3 -> 0 -> 1 -> 3 -> 3 -> 0 -> 1 -> 3 -> 3
LL3 Addr : (0x55a6c04ef7d0);(0x55a6c04ef7f0);(0x55a6c04ef810);(0x55a6c04ef830);(0x55a6c04ef850);(0x55a6c04ef870);(0x55a6c04ef890);(0x55a6c04ef8b0);(0x55a6c04ef8d0);(0x55a6c04ef8f0);(0x55a6c04ef910);(0x55a6c04ef930);
```

10. Use Inverse List (No.14) to inverse LL1 or LL2. There are also two methods for this. The first is without new allocated memory, and the second is with new allocated memory. For example, let LL1 and LL2 be reinitialized with these nodes.
```
Insert Command: 2

LL1      : 4 -> 2 -> 3
LL1 Addr : (0x55a6c04ef7b0);(0x55a6c04ef790);(0x55a6c04ef770);

LL2      : List is empty
LL2 Addr : 
```
10. First method inverse list, without new allocated memory. The result can be checked in Print List
```
Insert Command: 14

1. Without New Allocated Memory
2. With New Allocated Memory
Select Method: 1

1. LL1
2. LL2
Select Linked List: 1

LL1 Inversed
```

```
LL1      : 3 -> 2 -> 4
LL1 Addr : (0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);

LL2      : List is empty
LL2 Addr : 
```

10. As we can see, the LL1 is inversed, with the same memory address but the order is reversed. This algorithm is used from GeeksforGeeks with some modifications. This is the illustration for inverse LL algorithm.

![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif)
Inverse Linked List Algorithm (Source : GeeksforGeeks)

10. The second method, is similar to the first method but the result will be stored in a new allocated memory LL. This method utilizes either LL1 or LL2 for result storage so one of them must be empty. If LL1 and LL2 are not empty, this method cannot be used until one of them is empty. For example we want to inverse previous inversed LL but with second methods. The result will be stored in LL2 with new allocated memory

```
Insert Command: 14

1. Without New Allocated Memory
2. With New Allocated Memory
Select Method: 2

Inversed result stored in LL2 with new allocated memory
```
10. Use Print List to see each LL
```
Insert Command: 2

LL1      : 3 -> 2 -> 4
LL1 Addr : (0x55a6c04ef770);(0x55a6c04ef790);(0x55a6c04ef7b0);

LL2      : 4 -> 2 -> 3
LL2 Addr : (0x55a6c04ef970);(0x55a6c04ef950);(0x55a6c04ef750);
```

11. Use Quit (No.20) to quit program.

## Conclusion
This implementation of Singly Linked List might not be perfect, but we can learn a lot from this. The code also might not be efficient, but at least basic Singly Linked List operations are fucntional.

## Reference
GeeksforGeeks. 2020. *Linked List Set 1 (Introduction)*.  https://www.geeksforgeeks.org/linked-list-set-1-introduction/. Accessed on 23 May 2021.

GeeksforGeeks. 2021. *Reverse a linked list*. https://www.geeksforgeeks.org/reverse-a-linked-list/. Accessed on 28 May 2021.

CS Dojo. 2018. *Introduction to Linked Lists (Data Structures & Algorithms #5)*. https://www.youtube.com/watch?v=WwfhLC16bis. Accessed on 23 May 2021.

Firyanul Rizky. 2019. *[Konsep Dasar] Lingked List | Struktur Data & Pemrograman*. https://www.youtube.com/watch?v=1FPCl-xJzJY. Accessed on 23 May 2021.

GeeksforGeeks. 2021. *C++ Classes and Objects*. https://www.geeksforgeeks.org/c-classes-and-objects/. Accessed on 25 May 2021.

Dagozilla. 2021. *Encyclopedia cpp*. https://github.com/dagozilla/encyclopedia. Accessed on 25 May 2021.

TutorialsPoint. *C++ Dynamic Memory*. https://www.tutorialspoint.com/cplusplus/cpp_dynamic_memory.htm#:~:text=You%20can%20allocate%20memory%20at,operator%20is%20called%20new%20operator. Accessed on 25 May 2021.

GeeksforGeeks. 2019. *Double Pointer (Pointer to Pointer) in C*. https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/. Accessed on 25 May 2021.

GeeksforGeeks. 2020. *new and delete operators in C++ for dynamic memory*. https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/. Accessed on 25 May 2021.

Linuxize, 2021. *How to Change a Git Commit Message*. https://linuxize.com/post/change-git-commit-message/. Accessed on 25 May 2021.

GeeksforGeeks. 2021. *Doubly Linked List | Set 1 (Introduction and Insertion)*. https://www.geeksforgeeks.org/doubly-linked-list/. Accessed on 25 May 2021. 
