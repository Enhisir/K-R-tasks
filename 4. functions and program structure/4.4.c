#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

int main(void)
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
                printf("error: zero devisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod((double) pop(), (double) op2));
            else
                printf("error: zero devisor\n");
            break;
        case '$': // to show last operand use $
            printf("\t%.8g", back());
            break;
        case '|': // to duplicate the last operand use @
            duplicate();
            printf("\tOK");
            break;
        case '!':
            clear();
            printf("\tOK");
            break;
        case '?':
            stack_swap();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return EXIT_SUCCESS;
}

#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double back(void)
{
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("error: stack is empty");
        return 0.0;
    }
}

void stack_swap(void)
{
    if (sp < 2) {
        printf("error: can\'t use swap()");
        return;
    } 
    double f, s;
    f = pop();
    s = pop();
    push(f);
    push(s);
    printf("\tOK");
}

void duplicate(void)
{
    if (sp > 0)
        val[sp++] = val[sp - 1];
    else
        printf("error: stack is empty");
}

void clear(void)
{
    sp = 0;
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-')
        s[++i] = c;
    else if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
