#include<stdio.h>

int ft(int a)
{
    if(a <= 1)
        return(1);
    else
    {
        return( a * ft(a-1));
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    
    ft(t);
    printf("%d", ft(t));
    
}