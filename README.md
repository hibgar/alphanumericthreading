# alphanumericthreading

For this program, I needed to write a C++ program alphanumeric.cpp (create threads using the pthread library; Do not use C++ threads) that accepts a phrase of unspecified length as a command line argument.
The main() in this program should read the phrase from the terminal as input. This phrase should be saved into a global variable. This phrase or its parts can be directly accessed from the main() and / or from the threads. The main() has to create two concurrent threads. The threads should print as follows: 
The alpha thread should print the words that begin with an alphabet.
The numeric thread should print the words that begin with a number.

Goal 1: From the terminal, the program should read in the phrase. This phrase should be saved into a global variable.

Goal 2: The main should create 2 concurrent threads: one thread for printing words that begin with an alphabet, and the second thread for printing words that begin with a number. Each thread should call their own thread function: alpha and numeric respectively. Each thread should be sent their name as an argument through the thread function: alpha or numeric: this is what they will print in the output as shown above.
For creating each thread, you should use the pthread_create function.
For joining each thread, you should use the pthread_join function.

Goal 3: You will have to solve any race conditions using C++ language constructs, to simulate the working of locks.
You may encounter race conditions.

To solve it:
You are NOT allowed to use ANY pthread library or other POSIX synchronization primitives including but not limited to: semaphores, mutexes, mutex locks such as pthread_mutex_lock and pthread_mutex_unlock and conditional variables such as pthread_cond_wait and pthread_cond_signal etc. You should solve that race condition (if any) using another way, such as C++ language constructs.
You are also not allowed to use sleep() or sched_yield() 

Goal 4: If you split the input string into a set of words, say a vector, then such an object should be global. You should simultaneously be iterating over the vector in each of the alpha and the numeric thread functions. Even if you do not split the string, you should still be iterating over the string simultaneously in each of the alpha and the numeric thread functions. The index or the iterator used for iterating should be global.

The main( ) function (thread) should ONLY create 2 threads : one thread calls the alpha function, the other thread calls the numeric function.
If you have a loop that is creating 2 threads per iteration: when the loop runs n times: 2n threads are created.
But the requirement states: "The main() has to create two threads running functions (alpha and numeric respectively)"


Example output:

![image](https://github.com/hibgar/alphanumericthreading/assets/86140590/265d2ae2-9c73-4225-9f8b-7d93510d6e51)
