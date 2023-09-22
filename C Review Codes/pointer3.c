

#include <stdio.h>

int main( )
{
    int i = 3, *j, **k ;
    j = &i ;
    k = &j ;// K has the capability to hold address of pointer
    printf ( "\nAddress of i = %p", &i ) ; //print address of i
    printf ( "\nAddress of i = %p", j ) ; //print address of i
    printf ( "\nAddress of i = %p", *k ) ; //print address of i
    printf ( "\nAddress of j = %p", &j ) ; //print address of j
    printf ( "\nAddress of j = %p", k ) ; //print address of j
    printf ( "\nAddress of k = %p", &k ) ; //print address of k
    printf ( "\nValue of j = %p", j ) ; //print value of j, which is address of i
    printf ( "\nValue of k = %p", k ) ; //print value of k, which is address of j
    printf ( "\nValue of i = %d", i ) ; //print 3
    printf ( "\nValue of i = %d", * ( &i ) ) ; //print 3
    printf ( "\nValue of i = %d", *j ) ; //print print 3
    printf ( "\nValue of i = %d", **k ) ; //print 3. As *k = j, and *j = i, i=3
    return 0;
}
//output:
/*Address of i = 0x7ffee8ff6cc4
Address of i = 0x7ffee8ff6cc4
Address of i = 0x7ffee8ff6cc4
Address of j = 0x7ffee8ff6cc8
Address of j = 0x7ffee8ff6cc8
Address of k = 0x7ffee8ff6cd0
Value of j = 0x7ffee8ff6cc4
Value of k = 0x7ffee8ff6cc8
Value of i = 3
Value of i = 3
Value of i = 3
Value of i = 3
*/




