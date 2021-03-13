Exercise 3
==========


## 1. Reading (optional)


Browse/Read the chapter 3: "Control Flow" from [B. Kernighan, D. Ritchie, The C Programming Language, 2nd Ed., Prentice Hall, 1988](https://en.wikipedia.org/wiki/The_C_Programming_Language).



## 2. Loops: 'while', 'for' and 'do while'


Replace the following while loop by a  for loop. Test your solution on machine.



low = 0;
high = n - 1;
while (low <= high) {
 // do some actions
 ++low;
}

Same exercise as above, but use a do-while loop this time.


**Hint:** beware if n <= 0. Test your solution on machine.


## 3. goto & label, switch, break and continue


Replace the following for loop by a goto. Test your solution on machine.



for (i = 0; i < n; i++) {
 // do some actions
}

Rewrite the switch statement of the following code with goto's and labels. Test your solution on machine.



switch (i) {
 case 1: printf("case 1\n"); break;
 case 2: printf("case 2\n"); // Beware: no break !!!
 default: printf("default case\n"); break;
}

Replace the break of of the following code by a goto. Test your solution on machine.



for (i = 0; i < n; i++) {
 // do some actions 1
 if (cond1) break;
 // do some actions 2
}

Replace the continue of of the following code by a goto. Test your solution on machine.



for (i = 0; i < n; i++) {
 // do some actions 1
 if (cond1) continue;
 // do some actions 2
}

## 4. gdb – basics


Compile and execute the following program with gdb. Then conceive and comment a pertinent debug script (i.e. a sequence of gdb commands) for it, based on [commands introduced](https://unifr.coursc.ch/#gdb) and found in the man page of gdb.




**Hint:** observe the values of 'ctr' and 'i' at the end of lines 4 and 7;
and add a watch on the value of 'i' and 'res' while running the loop.




#include
int N = 3;
int main() {
 int ctr, i; // line 4
 int res;

 i = N; // line 7
 res = N;
 printf("res N i\n");
 for (ctr = 0; ctr < N; ++ctr, --i) {
 res = N/i;
 printf("%3i%3i%3i\n",res, N, i);
 }
 return 0;
}

## 5. gdb – core dump


Same exercise as (4) but now replace at line 11 the operator < by <=. Let the program crash and observe the core dump file with gdb.



**Hints:**
The core dump will be generated when you run the compiled program from the terminal. If no core dump file was generated, try running the following command then compile again:




$$ ulimit -c unlimited


The command required to read the dump file with GDB is:

$$ gdb {binary\_file\_path} {core\_file\_path}


Use the following commands to investigate the error scenario captured in the core dump:

% (gdb) bt
% (gdb) list
% (gdb) info locals
% (gdb) print


After checking the core dump with GDB, indicate which line caused the error and identify what error signal was issued by the OS. After identifying the signal, you can find out its [significance](https://www.gnu.org/software/libc/manual/html_node/Program-Error-Signals.html).


Hand in.
--------


Upload your answers on [Moodle](https://moodle.unifr.ch/mod/assign/view.php?id=857942).





