#include <stdio.h>

void vigesimalToDec(void);
int menu(void);
int myPow(int num,int power);
void Rhombus(void);
int charToDec(char c);
void isPowerOf2(void);
void differentBits(void);
int myAddition(signed num1,signed num2);
void myMult(signed num1,signed num2);


/******************
* Function Name:menu
* Input:Number from user
* Output: none
* Function Operation:Prints a menu for the the user to choose from
******************/
int menu(void)
{
int choice;
printf("Choose an Option:\n1.Rhombus\n2.Base 20 to Decimal\n3.Base to Decimal\n4.Pow2\n5.Different bits\n6.Add\n7.Multiply\n0.Exit\n");
scanf("%d", &choice);

if (choice>9){
    printf("Wrong choice!");
    printf("Choose an Option:\n1.Rhombus\n2.Base 20 to Decimal\n3.Base to Decimal\n4.Pow2\n5.Different bits\n6.Add\n7.Multiply\n0.Exit\n");
    scanf("%d",&choice);
}
return choice;
}
/******************
* Function Name:myPow
* Input: int num, int power
* Output: int temp
* Function Operation:Calculates power of number
******************/
int myPow(int num,int power)
{
    int temp = num;
    if(power ==0)
        temp=1;
    for (int i=1;i<power;i++)
    {
     temp*=num;
    }
    return temp;
}
/******************
* Function Name:Rhombus
* Input:natural number
* Output: none
* Function Operation:A Rhombus shape is printed
******************/
void Rhombus() {
    int x = 0;
    printf("Enter the sides length: \n");
    scanf("%d", &x);
    for (int i = 0; i <= x; i++)//loop for counting rows in upper half
    {
        for (int k = 1; k <= (2 * x) + 1; k++) //loop for counting columns
        {
            if (k == x - i)
                printf("/");
            else if (i == x && k == x+1)
                printf("+");
            else if (k == x + 1 && i!=x)
                printf("*");
            else if (k == x + 2 + i)
                printf("\\");
            else if (i == x && k == 1)
                printf("|");
            else if (i == x && k == (2*x+1))
                printf("|");
            else if (k<(x+2+i))
                printf(" ");

        }
        printf("\n");
    }
    for (int i = (x - 1); i >= 0; i--)//loop for counting rows in lower half
    {
        for (int k = 1; k <= (2 * x) + 1; k++)
        {
            if (k == (x + 2) + i)
                printf("/");
            else if (k == x + 1 && i != x)
                printf("*");
            else if (k == x - i)
                printf("\\");
            else if (k<(x+2+i))
                printf(" ");

        }
        printf("\n");
    }
}
/******************
* Function Name:charToDec
* Input: char c
* Output: int
* Function Operation:receives char and converts it to its decimal equivalent
******************/
int charToDec(char c)
{
    int decOut=0;
    switch (c){
        case '0':decOut=0;
            break;
        case '1':decOut=1;
            break;
        case '2':decOut=2;
            break;
        case '3':decOut=3;
            break;
        case '4':decOut=4;
            break;
        case '5':decOut=5;
            break;
        case '6':decOut=6;
            break;
        case '7':decOut=7;
            break;
        case '8':decOut=8;
            break;
        case '9':decOut=9;
            break;
        case 'A':
        case 'a':decOut=10;
            break;
        case 'B':
        case 'b':decOut=11;
            break;
        case 'C':
        case 'c':decOut=12;
            break;
        case 'D':
        case 'd':decOut=13;
            break;
        case 'E':
        case 'e':decOut=14;
            break;
        case 'F':
        case 'f':decOut=15;
            break;
        case 'G':
        case 'g':decOut=16;
            break;
        case 'H':
        case 'h':decOut=17;
            break;
        case 'I':
        case 'i':decOut=18;
            break;
        case 'J':
        case 'j':decOut=19;
            break;
        default:printf("ERROR in case switch\n");
            break;

    }
    return decOut;
}
/******************
* Function Name:vigesimalToDec
* Input: none
* Output: none
* Function Operation:receives a reverse vigesimal number and returns a decimal number
******************/
void vigesimalToDec()
{
    int error=0;
    char userNum=0;
    int counter=0;
    long temp=0;
    long sum=0;
    printf("Enter a reversed number in base 20:\n");
    scanf(" %c",&userNum);
    while(userNum != '\n')
    {

        if (((userNum>='0')&&(userNum<='9')) || ((userNum>='a')&&(userNum<='j')) || ((userNum>='A')&&(userNum<='J')))
        {
            temp = charToDec(userNum);
            temp *=myPow(20,counter);
            counter++;
            sum+=temp;
        }
        else
        {
            printf("Error! %c is not a valid digit in base 20\n",userNum);
            error++;


        }
        scanf("%c",&userNum);
    }
    if (error==0)
    printf("%ld\n",sum);



    }
/******************
* Function Name:baseToDec
* Input: none
* Output: none
* Function Operation:Receives a base and a number in that base from the user and converts it to a decimal number
******************/
void baseToDec()
{
    int userBase=0,counter=0,temp=0,sum=0,error=0;
    char userNum=0;
    printf("Enter a base (2-10):\n");
    scanf("%d",&userBase);
    printf("Enter a reversed number in base %d\n",userBase);
    scanf(" %c",&userNum);

    while(userNum != '\n')
    {
        temp = charToDec(userNum);
        if((temp/userBase)==0)
        {
            temp *= (myPow(userBase,counter));
            sum  += temp;
            counter++;
        }
        else
        {
            printf("Error! %d is not a valid digit in base %d\n",temp,userBase);
            error++;

        }

        scanf("%c",&userNum);
    }
    if(error==0)
    printf("%d\n",sum);

}
/******************
* Function Name:isPowerOf2
* Input: none
* Output: none
* Function Operation:Check if the number given by user is a power of 2
******************/
void isPowerOf2()
{
    unsigned userNum=0;
    printf("Enter a number\n");
    scanf("%d",&userNum);


    if ((userNum&(userNum-1))!=0)
        printf("%d is not a power of 2\n",userNum);
    else
        printf("%d is a power of 2\n",userNum);


}
/******************
* Function Name:differentBits
* Input: none
* Output: none
* Function Operation:Check to see how many different bits are there between 2 user input numbers
******************/
void differentBits()
{
    signed num1=0,num2=0;
    unsigned mask=1;
    int counter=0,size=0;
    printf("Enter two numbers:\n");
    scanf("%d%d",&num1,&num2);
    size=sizeof(num1);

    for(int i=0;i<=(size*8);i++)
    {
        if((num1&mask)!=(num2&mask))
        {
            counter++;
        }
        mask=mask<<1;
    }
    printf("There are %d different bits\n",counter);

}
/******************
* Function Name:myAddition
* Input: none
* Output: none
* Function Operation:Adds 2 user given numbers
******************/
int myAddition(signed num1,signed num2)
{
    signed mask=1,size=0,carry=0,sum=0,maskAndNum1=0,maskAndNum2=0,temp=0,bitCount=1;
    size=sizeof(int);

    for(int k=0;k<=size;k++)
        bitCount=bitCount<<1;


    for(int i=0;i<=bitCount;i++)
    {
        maskAndNum1=num1&mask;
        maskAndNum2=num2&mask;
        if (carry==0)
        {

            if((maskAndNum1==0)&&((maskAndNum2)==0))
                temp=temp&mask;
            else if(((maskAndNum1!=0)&&(maskAndNum2==0))||((maskAndNum1==0)&&(maskAndNum2!=0)))
                temp=temp|mask;
            else if(((maskAndNum1)!=0)&&((maskAndNum2)!=0))
            {
                temp=temp&mask;
                carry++;
            }

        }
        else if(carry==1)
        {
            if (((maskAndNum1) == 0) && ((maskAndNum2) == 0))
            {
                temp = temp | mask;
                carry--;
            }
            else if((((maskAndNum1)!=0)&&((maskAndNum2)==0))||(((maskAndNum1)==0)&&((maskAndNum2)!=1)))
            temp=temp&mask;
            else if(((maskAndNum1)!=1)&&((maskAndNum2)!=1))
            temp=temp|mask;


        }
        else
            printf("Error, carry is not 1 or 0\n");
        sum=sum|temp;
        temp=0;
        mask=mask<<1;

    }

    return (sum);
}
/******************
* Function Name:myMult
* Input: none
* Output: none
* Function Operation:multiplicate 2 user given numbers
******************/
void myMult(signed num1,signed num2)
{
    signed sum=0;
    if (num1>0&&num2<0)
    {
        //num2=(!num2)+1;
        for(int i=1;i<=num1;i++)
            sum=myAddition(sum,num2);
        printf("%d\n",sum);
    }
    else if (num1<0&&num2<0)
    {
        num2=(~num2)+1;
        num1=(~num1)+1;
        for(int i=1;i<=num2;i++)
            sum=myAddition(sum,num1);
        printf("%d\n",(~sum)+1);
    }

    else if (num1<0&&num2>0)
    {

        for(int i=1;i<=num2;i++)
            sum=myAddition(sum,num1);
        printf("%d\n",sum);
    }
    else
    {
        for(int i=1;i<=num2;i++)
            sum=myAddition(sum,num1);
        printf("%d\n",sum);
    }




}






int main()
    {
        int num1=0,num2=0;
        char userChoice;
        userChoice = 'y';
        while (userChoice == 'y') {
            switch (menu())
            {
                case 1:
                    Rhombus();
                    break;
                case 2:
                    vigesimalToDec();
                    break;
                case 3:
                    baseToDec();
                    break;
                case 4:
                    isPowerOf2();
                    break;
                case 5:
                    differentBits();
                    break;
                case 6:
                    printf("Enter two numbers:\n");
                    scanf("%d",&num1);
                    scanf("%d",&num2);
                    printf("%d\n",myAddition(num1,num2));
                    break;
                case 7:
                    printf("Enter two numbers:\n");
                    scanf("%d",&num1);
                    scanf("%d",&num2);
                    myMult(num1,num2);
                    break;
                case 0:
                    userChoice='n';
                    break;



            }

            fflush(stdin);

        }


        return 0;
    }
