/*------------------------------------------------------------------------
Reverse Polish Calculator                                       -- kr76-79

usage: progr_name [input_file] [output_file]
example: calc 2 3*

Adapted by Beat Hirsbrunner, October 2011, rev. Oct. 2013
------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>	// for atof()

#define MAXOP  100	// max size of operand or operator
#define NUMBER '0'	// signal that a number was found

int getop(char []);
void push(double);
double pop(void);

// reverse Polish calculator --- kr76
main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


/* ----------------------------------- */
/* Stack "module" --------------- kr77 */
/* ----------------------------------- */

#define MAXVAL 100	 // maximum depth of val stack

int    sp = 0;		 // next free stack position
double val[MAXVAL];	 // value stack

// push: push f onto value stack --- kr77
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;

    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack --- kr77
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}



/* ----------------------------------- */
/* getop "module" --------------- kr78 */
/* ----------------------------------- */

#include <ctype.h>  // isdigit

int getch(void);
void ungetch(int);

// getop: get next operator or numeric operand --- kr78
// int getop(char s[])
// {
//     int i, c;

//     while ((s[0] = c = getch()) == ' ' || c == '\t')
//         ;
//     s[1] = '\0';
//     if (!isdigit(c) && c != '.')
//         return c;		// not a number
//     i = 0;
//     if (isdigit(c))		// collect integer part
//         while (isdigit(s[++i] = c = getch()))
//             ;
//     if (c == '.')		// collect fraction part
//         while (isdigit(s[++i] = c = getch()))
//             ;
//     s[i] = '\0';
//     if (c != EOF)
//         ungetch(c);
//     return NUMBER;
// }

/*------------------------------------------------------*/
// getop: get next operator or numeric operand --- BH, Oct. 2013
// (a simplified version of kr78: numbers are restricted to integers)


#define BUFSIZE 100
#define GET_CACHED_OR_GETCHAR(buffer, i) (i > 0 ? buffer[--i] : getchar())

int getop(char s[]) {
    // like the global variables
    static char buffer[BUFSIZE];
    static int buffer_i = 0;

    char c;
    int i=0;

    // either we still have characters in the buffer or else
    // call `getchar` to get the next character
    while ((c = GET_CACHED_OR_GETCHAR(buffer, buffer_i)) == ' ' || c =='\t') ; // skip spaces

    if (c<'0' || c>'9')                      // c is not a digit
        return c;

    s[0]=c;
    while(isdigit(s[++i] = c = GET_CACHED_OR_GETCHAR(buffer, buffer_i)))     // collect integer
        ;
    s[i]='\0';                               // string terminator

    // save the last read character
    if (c!=EOF) {
        if (buffer_i < BUFSIZE)
            buffer[buffer_i++] = c;
        else
            printf("Buffer is full: %s[%d]\n", buffer, buffer_i);
    }

    return NUMBER;
}
/*------------------------------------------------------*/



/* ------------------------------------------- */
/* getch_ungetch "module" --------------- kr79 */
/* ------------------------------------------- */


char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf

int getch(void)	// get a (possibly pushed back) character --- kr79
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	// push character back on input --- kr79
{
    if ( bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
