/******************
* Function Name: intLen
* Input:unsigned number
* Output: none
* Function Operation:returns the number of digits in a number
******************/
//DELETE ME
int intLen(int num)
{
    int numLength=0;
    if (num >= 1000000000)
        numLength=10;
    else if (num >= 100000000)
        numLength=9;
    else if (num >= 10000000)
        numLength=8;
    else if (num >= 1000000)
        numLength=7;
    else if (num >= 100000)
        numLength=6;
    else if (num >= 10000)
        numLength=5;
    else if (num >= 1000)
        numLength=4;
    else if (num >= 100)
        numLength=3;
    else if (num >= 10)
        numLength=2;
    else if (num<10)
        numLength=1;
    return numLength;
}