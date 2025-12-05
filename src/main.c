#include<stdio.h>


int sum(int x , int y){
    return (x+y);
}
int main(int argc, char const *argv[])
{
    int Num1, Num2, Add;

    printf("Enter 2 Numbers : ");
    scanf("%d%d",&Num1,&Num2);

    Add = sum(Num1,Num2);

    printf("%d",Add);
    return 0;
}
