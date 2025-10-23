#include<stdio.h>

void set(int x, int y, int n)
{
 

      if((x/n)%3 == 1 && (y/n)%3 == 1 )
             printf(" "); 
      else
         {
             if (n == 1)  // n이 3이된거
                 printf("*");
             else
                set(x, y, n/3);
         }
    

}

int main()
{
    int t;
    scanf("%d", &t);
        
    for(int i = 0; i < t;i++)
    {
        for(int j = 0; j < t; j++)
            set(i, j, t);

        printf("\n");
    }
}

    
