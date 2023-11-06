#include<studio.h>
#include<math.h>
lang name(long num);
{
    lang num;
    printf("Enter any number to convert into binary");
    scanf("%ld",&num);
    printf("%ld",name(num));

    return 0;
}

long name(long num) {
    long rem,bin=0,i=1;
    while(num!=0)
    {
        rem=num%2;
        num=num/2;
        bin=bin+(rem*i);
        i=i*10;
    }
    return bin;
    }
    
