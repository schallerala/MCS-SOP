Exercise 2: Memory \& scanf
===========================


## 1. Reading (optional)



Browse/Read the chapeter 2 : "Types, Operators and Expressions" from [B. Kernighan, D. Ritchie, The C Programming Language, 2nd Ed., Prentice Hall, 1988](https://unifr.coursc.ch/https://en.wikipedia.org/wiki/The_C_Programming_Language).



## 2. Word Count - Some Shell Commands



The [program kr020.c](https://unifr.coursc.ch/2/kr020.c) from the book reads a file from the standard input, counts the number of lines, words and characters, and prints these numbers. Download it, save it with the name "wcount.c" and compile it (see also [compiler](https://unifr.coursc.ch/#compiler)):



```shell
$ gcc -o wcount wcount.c
```

Test it and explain the following Unix commands (consult the man pages, if some Unix commands are not familiar to you):

> EOF Reminder: In most Unix shells, the End-of-file character (EOF) is produced by hitting <return>, followed by <Ctrl-D>. If this does not work, try <return>, followed by <Ctrl-Option(alt)-D>.




```shell
$ ./wcount
$ ./wcount < wcount.c
$ ./wcount < wcount > test % cat wcount.c | ./wcount
$ grep { wcount.c
$ grep { wcount.c | ./wcount
$ grep -l { * | ./wcount
```

## 3. Type Conversion, Casting and ASCII



What is the output of the C code excerpt the following code? Also explain, for each output, why an explicit casting is necessary or not.




Hint: for line 1 and 2, consult the [ASCII table](https://unifr.coursc.ch/#ascii).



```c
char c='A'; int i=65; float pi=3.14;
printf("%c %i\n", c, c);
printf("%c %i\n", i, i);
printf("%f %i\n", pi, (int)pi);
```

## 4. Constant, Variable, Escape Character ‘\’, and Octal resp. Hexadecimal Digits



What is the output of the C code excerpt of the following code, and explain.
**Hint:** consult the ASCII table.


```c
// macro definition in octal
#define AT '\100'
// variable in hexadecimal
char at = '\x40';
printf("%c %i %o %x\n", '@', '@', '@', '@');
printf("%c %i %o %x\n", AT, AT, AT, AT);
printf("%c %i %o %x\n", at, at, at, at);
```


## 5. enum Type


What is the output of the C code excerpt of the following code, and explain.

```c
// declaration of variable b, without tag
enum {FALSE, TRUE} b;
b = TRUE;
printf("%i %i\n", b, FALSE);

// enum declaration, with tag 'color_tag'
enum color_tag {RED, GREEN, BLUE};

// declaration of variables ci
enum color_tag c1;
enum color_tag c2;
enum color_tag c3;

c1 = RED;
c2 = c1+1;
c3 = BLUE;
printf("%i %i %i\n", c1, c2, c3);
```



## 6. Logical Expressions



Write down the truth tables of the following C expressions, and for line 2 also give the value of p at the end of the evaluation by a C compiler:


```c
p || !q;
p && (p == q);
// Beware: p == q
p && (p = q) || (p = !q);
// Beware: p = q
```

## 7. scanf


###
A simple program with input errors:


Look at the program excerpt in the following code What are the values of str, i and d at the end of lines 1, 2 and 3 if the input is: AA 33 55 ZZ 77 99? Explain why.


```c
char str[3];
int i;
int d;
d = scanf("%s %i", str, &i);
d = scanf("%s %i", str, &i);
d = scanf("%s %i", str, &i);
```

### Your own simple program.


Write a program which reads a character, an integer, a string and a float, and prints them to the standard output. Test your answer on a machine.


## 8. Order of Evaluation



Explain why the following code can produce different results with different compilers.



```c
f() + g();
printf("%i\n", ++n, f(n));
```


## Hand in.



Upload your answers on [Moodle](https://moodle.unifr.ch/mod/assign/view.php?id=857942).





