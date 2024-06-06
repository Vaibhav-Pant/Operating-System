
# Operating System Lab Programs/Codes

This repository contains Programs for the Operating System Lab Course. Here I provide C Programs and some shell scripts and also the problem statement for some. If you find any error in code or the code is giving some Wrong Output you can raise a issue here. If you like it, consider giving a Star !!



## Illustration

### 1) Concurrency  

#### Dining Philosopher Problem

Problem:

The Dining Philosopher Problem states that K philosophers are seated around a circular table with one chopstick between each pair of philosophers. There is one chopstick between each philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him. One chopstick may be picked up by any one of its adjacent followers but not both. 

Output:

![output1](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/bf33f8db-95b7-4aed-89c6-9e7f40f464d7)

#### Producer Consumer Problem

Problem:

We have a buffer of fixed size. A producer can produce an item and can place in the buffer. A consumer can pick items and can consume them. We need to ensure that when a producer is placing an item in the buffer, then at the same time consumer should not consume any item.

Output:

![output2](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/5dacc4a0-ae04-4ab0-bc49-0c04898f5a9a)


### 2) CPU Scheduling Algorithms

#### File structure

![structure](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/4eb0a49c-1d58-49aa-ab58-6d0a4ac5e8b5)

#### FCFS (First Come First Serve)

![fcfs](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/dee73f58-6cbb-4aa0-a21c-aee98b7cb204)

#### SJF (Shortest Job First) - Non Preemptive/ Preemptive

![sjf_np](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/70f93d1e-19db-4b45-8181-8225bd847987)

![sjf_p](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/fa1d5caa-27e5-4fd7-a31d-7d87ab40862e)

#### Priority - Non Preemptive/ Preemptive

![priority_np](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/3467b818-f02c-4c8b-b1c3-c848c43fe2d7)

![priority_p](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/7cae154b-5a35-435c-9ae3-96e9e4502abd)

#### Round Robin

![round_robin](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/67eb2b31-463c-47dd-b013-a15adca9ac83)

### 3) Disk Scheduling

#### FCFS (first come first server)

![fcfs](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/efa0eaaf-de9d-499d-ae8b-e4fad3632a85)

#### SSTF (Shortest seek time first)

![sstf](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/dd43082d-abfd-4021-8a42-0c3888bd6994)

#### SCAN - Direction Left/Right

![scan_l](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/f0bb3aef-0267-4597-91a1-9ebd91c40a32)

![scan_r](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/c1250b8d-c714-43a6-9306-fc6f462b4915)

#### Circular - SCAN

![cscan](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/d752defd-0e86-4cba-8f12-560a790c030c)

#### LOOK - Direction Left/Right

![look_l](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/4f4dc78f-d312-4ae0-bba4-20b68b46a13a)

![look_r](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/85875822-1650-4c7a-8a5e-c81da4ce7558)


#### Circular - LOOK 

![clook](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/4f7e75ed-85ba-4d4f-9cf4-ff3a4688a996)

### 4) IPC (Inter Process Communication)

#### Question 1
Write a C program using Pipes for the following
a) Create 2 Process (Child and Parent)
b) Child Process must request the Parent process to compute the
factorial of a number.
c) Child Process must read a number from the user.

Output:

![ques1](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/76fd17fa-3e96-499b-a33b-d2f9fd118ea0)

#### Question 2
Write a C Program using Named Pipes (FIFOS)
a) Create 2 Process(Sender and Receiver)(Un related - i.e, belonging
to 2 separate applications)
b) Sender process has to send u’r details (RegNo, Name, Course,
School) to the Receiver process.

Output:

![ques2](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/347dc0f6-e79c-4e32-b502-3cbdc3d9681a)


#### Question 3
Use message queues in a C programme to construct a basic conversation
programme between two unrelated, independent processes. Additionally,
the programme must terminate until one of the processes posts the
message "stop."

Output:

![ques3](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/a24efd3d-f2aa-42fc-9208-2626cb0dca32)

#### Question 4
Write a C Program using Shared Memory b/w 2 processes for exchanging
the below message:
“Inter-Process Communication (IPC) plays a vital role in the world
of operating systems, enabling different processes to communicate
and cooperate with each other. IPC is crucial for multi-tasking,
enabling processes to share data, synchronize their activities,
and collaborate effectively”

Output:

![ques4](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/f324deb3-56a1-44d7-8d1a-3d277f0b3ee3)

### 5) Memory Allocation

#### First fit Allocation
First-fit allocation is a memory allocation algorithm that goes through a list of free blocks of memory and assigns the task to the first block large enough to accommodate the request.

![ff](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/bc6dee54-7d7c-468e-b2e1-73dfb963c51a)

#### Best fit Allocation
In Best-Fit, the operating system searches through the list of free blocks of memory to find the block that is closest in size to the memory request from the process

![bf](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/2a4bf6fa-50e5-415c-8aed-218831c3d457)

#### Worst fit Allocation
It involves finding and allocating the largest available block of memory to the process in question.

![wf](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/81087c98-a271-4c91-ac05-6b982dad2f64)


### 6) Page Replacement Algorithms

#### FIFO ( First in first out )
FIFO algorithm replaces the oldest (First) page which has been present for the longest time in the main memory.

![fcfs](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/0a3f0ed5-90de-421e-8962-1898dd6197a0)

#### LRU ( Least Recently used )
This algorithm is based on the strategy that whenever a page fault occurs, the least recently used page will be replaced with a new page.

![lru](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/7626a9cb-1347-42b6-9d71-1ebce350846b)

#### Optimal Replacement Algorithms
This algorithm replace the page that will be referenced furthest in the future or not at all.

![optimal](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/9478d53d-f0c9-4f28-87cd-0e18960e2a57)

#### LFU ( Least Frequently used )
The LFU algorithm counts how often an item is needed; those used less often are discarded first. This is similar to LRU, except that how many times a block was accessed is stored instead of how recently.

![lfu](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/2a607a87-1c87-4fb7-9c76-82bca772483a)


### 7) System Calls

#### Question 1_A
Write a function foo(int fd, char* buf, int b_size, int n, int skip) that reads to buf from file with file descriptor fd, n blocks of size b_size each. The last argument specifies how many bytes to skip after reading each block. Return -1 if the operation is unsuccessful. Else return total number of bytes read.

Output:

![1a](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/bcbbda1f-3b32-4f5f-8575-7bce6e152365)

#### Question 1_B
Write a program to read all txt files (that is files that ends with .txt) in the current directory and merge them all to one txt file and returns a file descriptor for the new file.

Output:

![1b](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/1091ea4d-355f-46fd-bc93-1ceec3126795)

#### Question 1_C
Write a program that takes a string as an argument and return all the files that begins with that name in the current directory and its sub directories. For example, > ./a.out foo will return all file names that begins with foo.

Output:

![1c](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/b278851d-966a-4da9-93e8-30f581a7d25e)

#### Question 1_D
Write a program that will categorize all files in the current folder based on their file type. That is all .txt file in one folder called txt, all .bmp files in another folder called bmp etc. The argument to the program is a folder name.

Output:

![1d](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/e5d822dd-728b-4ef9-bc78-b69e28116128)

#### Question 1_E
Given a directory, write a program that will find all files with the same name in the directory and its sub directories. Show their name, which folder they are in and what day they were created. Expand the program to remove all duplicate copies based on user input. That is, ask user if each one of the file is to be kept or deleted. Based on user input, perform the appropriate action.

Output:

![1e](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/bbde53fc-4d67-4dae-ab11-adfcd5811a44)

#### Question 2_A
Create two functions: one to generate the list of Odd_Numbers b/w 'n' and 'm', and another to generate Even_Numbers b/w 'n' and 'm'. In order to invoke the aforementioned techniques, construct a C programme that creates two processes, one of which calls the Even_Number list and the other the Odd_Number list

Output:

![2a](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/a3c1ca8e-8a41-4255-bd13-39aec974af0b)

#### Question 2_B
Develop two distinct programmes. One should be used to generate Fibonacci Series upto 'n' terms (let's say Fibo.c), and the other should produce a list of PrimeNumbers b/w 'n' and 'm' (let's say Prime.c). Now develop a C programme that uses fork() to split into two processes, one that runs Fibo.c and the other that runs Prime.c.

Output:

![2b](https://github.com/Vaibhav-Pant/Operating-System/assets/132343877/7eb203d1-a313-4d83-89e2-f502e6ed141d)
