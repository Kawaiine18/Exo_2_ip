#include "netmask.h"
void getdata(char **ip)
{
    int d = 255;
    *ip = (char *)malloc(d * sizeof(char));
    printf("Enter CIDR:");
    scanf("%s", *ip);
}
int* netmaskValue(char *ip)
{
    int i;
    int j;
    int tmp1,
        tmp2,
        tmp3,
        tmp4;
    int t0[8];
    int t1[8];
    int t2[8];
    int t3[8];
    int bits[32];
    int t[8];
    int tab[4];
    int netmask[4];

    If(sscanf(ip, "%d.%d.%d.%d/%d", &tab[0], &tab[1], &tab[2], &tab[3], &tab[4]) ==5)
    {
    for (i = 0; i < tab[4]; i++)
    {
        t[i] = 1;
        bits[i] = t[i];
    }
    for (i = tab[4]; i < 32; i++)
    {
        t[i] = 0;
        bits[i] = t[i];
    }
    for (i = 0; i < 8; i++)
    {
        t0[i] = bits[i];
    }
    
    netmask[0] = bitToDec(t0);
    for (i = 8,j=0; i < 16 && j<8 ; i++, j++)
    {
              t1[j]=bits[i];
            
    }
    netmask[1] = bitToDec(t1);
    for (i = 16, j=0; i < 24 && j<8; i++, j++)
    {
            t2[j] = bits[i];
    }
    netmask[2] = bitToDec(t2);
    for (i = 24, j=0; i < 32, j<8; i++, j++)
    {
            t3[j] = bits[i];
            
    }
    netmask[3] = bitToDec(t3);
    return (netmask);
} 
else
{
printf("CIDR invalid!! ") ;
} 
}

int bitToDec(int t[])
{
    int i;
    int j;
    int dec=0;

    for(i=0, j=7; i<8 && j>=0; i++, j--)
    {
        dec += pow(2, j)*t[i];
    }
    return (dec);
}
void displayIntTab(int t[])
{
    int i;

    printf("\n");
    for(i=0; i<4; i++)
    {
        printf("%d", t[i]);
        if(i!=3)
        {
            printf(".");
        }
    }
}
