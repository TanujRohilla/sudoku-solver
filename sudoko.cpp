#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

bool checkRow(int arr[9][9], int row, int num) {
    /*
        Objective: Check whether number present in row or not
        Input:     array, row, number to be searched in row i.e, num
        Return:    0 if number is present in row, 1 if number is not present in row
    */

    for (int i=0; i<9; i++) {
        if(arr[row][i] == num) 
            return true;
    }
    return false;
}

bool checkCol(int arr[9][9], int col, int num) {
    /*
        Objective: Check whether number present in column or not
        Input:     array, row, number to be searched in column i.e, num
        Return:    0 if number is present in column, 1 if number is not present in column
    */

    for (int i=0; i<9; i++) {
        if(arr[i][col] == num) 
            return true;
    
    }
    return false;
}

bool checkBlock(int arr[9][9], int startRow, int startCol, int num) {
    /*
        Objective: Check whether number present in block or not
        Input:     array, index (i,j) of number , number to be searched in block i.e, num
        Return:    false if number is present in row, true if number is not present in row
    */

    for(int i=startRow; i<3; i++) {
        for(int j=startCol; j<3; j++) {
            if(arr[startRow+i][startCol+j] == num) 
                return true;
        }
    }
    return false;
}


bool findUnassigned (int arr[9][9], int &row, int &col) {
    /*
        Objective: finding the unassigned in array
        Input:     array, row, column
        Return:    false if no 0 is found, true if 0 is found
    */
    
    for (row=0; row<9; row++) {
        for (col=0; col<9; col++){
            if (arr[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isValid (int arr[9][9],int row, int col, int num) {
    /*
        Objective: Check whether particular number is satisfied the rule of sudoko
        Input:     array, row, column, num
        Return:    false if number doesnot satisfied rule, true if number satisfied rule
    */
    if ( checkRow(arr, row, num) == false && checkCol(arr, col, num) == false && checkBlock(arr, row - row%3, col - col%3, num) == false) {
        return true;
    }
    return false;
}

bool solveSudoko(int arr[9][9]) {
    /*
        Objective: Solve sudoko problem
        Input:     array, index (i,j) of number , number to be searched in block i.e, num
        Return:    false if number is present in row, true if number is not present in row
    */
    int row,col;
    if (findUnassigned(arr, row, col) == false)
        return true;

    for (int i=1; i<=9; i++) {
        if( isValid(arr, row, col, i) == true ) {
            arr[row][col]=i;
            if (solveSudoko(arr)) {
                return true;
            }

            arr[row][col]=0;
        }

    }
    return false;
}

int main()
{
    int arr[9][9];
    bool result;

    for (int i=0;i<9;i++)       // input sudoko matrix
        for(int j=0;j<9;j++)
            cin>>arr[i][j];


  
    result = solveSudoko(arr);
    
    if (result == true) {
        cout<<"\nSolution of Sudoku:\n\n";
        cout<<"\n _______________________________\n";
        cout<<" |         |         |         |\n";
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if (j==0)
                    cout<<" |  ";
                cout<<arr[i][j]<<" ";
                if ( j%3 == 2 )
                    cout<<" |  ";

            }
            if (i%3==2) {
                cout<<"\n |_________|_________|_________|\n";
                cout<<" |         |         |         |";
            }

            cout<<"\n";
        }
    }

    else {
        cout<<"Sudoko cannot be solved";
    }
}