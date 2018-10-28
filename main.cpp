#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int checkRow(int arr[9][9],int row,int num)
{
    /*
        Objective: Check whether number is present in row or not
        Input:     array, row, number to be searched in row i.e, num
        Return:    0 if number is present in row, 1 if number is not present in row
    */

    int flag=0;
    for (int i=0;i<9;i++)
    {
        if(arr[row][i]==num)
        {
                flag=1;
                break;
        }

    }
    return (flag==0)?0:1;
}

int checkCol(int arr[9][9],int col,int num)
{
    /*
        Objective: Check whether number is present in column or not
        Input:     array, row, number to be searched in column i.e, num
        Return:    0 if number is present in column, 1 if number is not present in column
    */

    int flag=0;
    for (int i=0;i<9;i++)
    {
        if(arr[i][col]==num)
        {
                flag=1;
                break;
        }

    }
    return (flag==0)?0:1;
}

int checkBlock(int arr[9][9],int i,int j,int num)
{
    /*
        Objective: Check whether number is present in block or not
        Input:     array, index (i,j) of number , number to be searched in block i.e, num
        Return:    0 if number is present in row, 1 if number is not present in row
    */

    int a,b,block,flag=0;

    // determining block number

    if ( i<=2 && i>=0 )
    {
        if( j<=2 && j>=0 )
        {
            block=1;
            a=0,b=0;
        }
        else if( j<=5 && j>=3 )
        {
            block=2;
            a=0,b=3;
        }
        else
        {
            block=3;
            a=0,b=6;
        }

    }

    else if ( i<=5 && i>=3 )
    {
        if( j<=2 && j>=0 )
        {
            block=4;
            a=3,b=0;
        }
        else if( j<=5 && j>=3 )
        {
            block=5;
            a=3,b=3;
        }
        else
        {
            block=6;
            a=3,b=6;
        }

    }

    else
    {
        if( j<=2 && j>=0 )
        {
            block=7;
            a=6,b=0;
        }
        else if( j<=5 && j>=3 )
        {
            block=8;
            a=6,b=3;
        }
        else
        {
            block=9;
            a=6,b=6;
        }
    }


    int i_max=a+3,j_max=b+3;  // initial position of block
    for(int s=a;s<i_max;s++)
    {
        for(int c=b;c<j_max;c++)
        {
            if(arr[s][c]==num)
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
        {
                break;
        }


    }
    return (flag==1)?1:0;
}

int main()
{
    int arr[9][9];
    int count_row=0,count_col=0,count_block=0,pos_i,pos_j,flag=0,ans;
    int i,j,k;

    for (int i=0;i<9;i++)       // input sudoko matrix
        for(int j=0;j<9;j++)
            cin>>arr[i][j];

    l1:
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                flag=0;
                for(k=1;k<=9;k++)
                {
                    count_row=checkRow(arr,i,k);
                    count_col=checkCol(arr,j,k);
                    count_block=checkBlock(arr,i,j,k);

                    if(count_row==0 && count_col==0 && count_block==0)
                    {
                            flag+=1;
                            pos_i=i;
                            pos_j=j;
                            ans=k;

                    }

                }

                if(flag==1)
                {
                    arr[pos_i][pos_j]=ans;
                    flag=0;
                    goto l1;
                }
            }

        }

    }
    cout<<"\nSolution of Sudoku:\n\n";
    cout<<"\n _______________________________\n";
    cout<<" |         |         |         |\n";
    for(i=0;i<9;i++)
    {

        for(j=0;j<9;j++)
        {
            if (j==0)
                cout<<" |  ";
            cout<<arr[i][j]<<" ";
            if ( j%3 == 2 )
                cout<<" |  ";

        }
        if (i%3==2)
        {
            cout<<"\n |_________|_________|_________|\n";
            cout<<" |         |         |         |";
        }

        cout<<"\n";


    }

}
