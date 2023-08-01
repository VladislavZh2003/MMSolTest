#include <stdio.h>
  
void flipOddBits(int *mask);
void mirrorBits(int *mask); 
  
int main()
{
    int numb = 7;
    flipOddBits(&numb);
    printf("\n");
    mirrorBits(&numb);
    return 0;
}

void flipOddBits(int *mask)
{
    
    int res = 0, count = 0;
    for (int temp = *mask; temp > 0; temp >>= 1) {
  
        
        if (count % 2 == 0)
            res |= (1 << count);     
  
        count++;
    }
  
    printf("0b%d",*mask ^ res);
}

void mirrorBits(int *mask)
{
    int bits = sizeof(*mask) * 8;
    int mirror_num = 0;
    int i;
    for (i = 0; i < bits; i++) {
        if ((*mask & (1 << i)))
            mirror_num |= 1 << ((bits - 1) - i);
    }
    printf("%u",mirror_num);
}