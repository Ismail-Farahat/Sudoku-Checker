#include <stdio.h>
#include <stdlib.h>

char input[50];                     //to store the file name that the user will enter as input
char sudoku_line[256];              //declare sudoku_line to store a line from the txt file
char sudoku_str[256]={};            //to store the entire txt file as string
char sudoku_str_no_spaces[256]={};  //to remove spaces from sudoku_str and store the new string without spaces into this string
char sudoku_element[2]={};          //to store only one char from the string sudoku_str
int sudoku[9][9];                   //the final array that holds the values of the sudoku solution
int sudoku_digit;                   //variable for storing single digit in every process
int block_array[9][9];              //2d array to store blocks elements (every block as a row)
int wrong_count = 0;                //variable for counting the number of discovered mistakes


int main()
{
    //to get the file name from the user
    printf("Please, Enter the file name: \n");
    fgets(input,10,stdin);
    FILE * fp = fopen(input,"r");
    //to make sure that the file is readable
    if (fp == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //to read the txt file line by line and store these lines in the sudoku_str
        for(int i=0; i<9; i++)
        {
            strcat(sudoku_str, fgets(sudoku_line, sizeof(sudoku_line), fp));
        }
        //close the file
        fclose(fp);
        //the sudoku txt file should have 169 char including the spaces ,newlines and chars
        //to check if the file in the right format
        if(strlen(sudoku_str) != 169)
        {
            printf("File is not in the right format.\n");
            return 1;
        }
        //to remove the spaces from sudoku_str and store the new string without spaces in sudoku_str_no_spaces
        for(int k=0; k<169; k++)
        {
            if((sudoku_str[k] != ' '))
            {
                sudoku_element[0] = sudoku_str[k]; //store the char into sudoku_element[0] to combine it with sudoku_str_no_spaces
                //to check if the element is digit or not
                if((sudoku_str[k] >= 'a' && sudoku_str[k] <= 'z') || (sudoku_str[k] >= 'A' && sudoku_str[k] <= 'Z'))
                {
                    printf("File is not in the right format, there are some elements that are not digits.\n");
                    return 2;
                }
                strcat(sudoku_str_no_spaces, sudoku_element); //to combine sudoku_element[0] with sudoku_str_no_spaces
            }
        }
        //to store the string chars into an int array to make file ready for checking process
        int jj=0; //this variable is a counter to fill the rows of the array
        for(int kk=0; kk<97; kk++) //97 is the size of the string without spaces
        {
            sudoku_digit = sudoku_str_no_spaces[kk] - '0'; //to covert it to int
            if(kk<9)
            {
                sudoku[0][jj] = sudoku_digit; //to store the first row
                //to store blocks as 2d array
                if(jj<3) block_array[0][jj] = sudoku_digit; //store the first three elements in block 1
                else if(jj<6) block_array[1][jj-3] = sudoku_digit; //store the first three elements in block 2
                else block_array[2][jj-6] = sudoku_digit; //store the first three elements in block 3
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>10 && kk<20)
            {
                sudoku[1][jj] = sudoku_digit; //to store the second row
                //to store blocks as 2d array
                if(jj<3) block_array[0][jj+3] = sudoku_digit; //store the second three elements in block 1
                else if(jj<6) block_array[1][jj] = sudoku_digit; //store the second three elements in block 2
                else block_array[2][jj-3] = sudoku_digit; //store the second three elements in block 3
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>21 && kk<31)
            {
                sudoku[2][jj] = sudoku_digit; //to store the third row
                //to store blocks as 2d array
                if(jj<3) block_array[0][jj+6] = sudoku_digit; //store the third three elements in block 1
                else if(jj<6) block_array[1][jj+3] = sudoku_digit; //store the third three elements in block 2
                else block_array[2][jj] = sudoku_digit; //store the third three elements in block 3
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>32 && kk<42)
            {
                sudoku[3][jj] = sudoku_digit; //to store the forth row
                //to store blocks as 2d array
                if(jj<3) block_array[3][jj] = sudoku_digit; //store the first three elements in block 4
                else if(jj<6) block_array[4][jj-3] = sudoku_digit; //store the first three elements in block 5
                else block_array[5][jj-6] = sudoku_digit; //store the first three elements in block 6
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>43 && kk<53)
            {
                sudoku[4][jj] = sudoku_digit; //to store the fifth row
                //to store blocks as 2d array
                if(jj<3) block_array[3][jj+3] = sudoku_digit; //store the second three elements in block 4
                else if(jj<6) block_array[4][jj] = sudoku_digit; //store the second three elements in block 5
                else block_array[5][jj-3] = sudoku_digit; //store the second three elements in block 6
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>54 && kk<64)
            {
                sudoku[5][jj] = sudoku_digit; //to store the sixth row
                //to store blocks as 2d array
                if(jj<3) block_array[3][jj+6] = sudoku_digit; //store the third three elements in block 4
                else if(jj<6) block_array[4][jj+3] = sudoku_digit; //store the third three elements in block 5
                else block_array[5][jj] = sudoku_digit; //store the third three elements in block 6
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>65 && kk<75)
            {
                sudoku[6][jj] = sudoku_digit; //to store the seventh row
                //to store blocks as 2d array
                if(jj<3) block_array[6][jj] = sudoku_digit; //store the first three elements in block 7
                else if(jj<6) block_array[7][jj-3] = sudoku_digit; //store the first three elements in block 8
                else block_array[8][jj-6] = sudoku_digit; //store the first three elements in block 9
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>76 && kk<86)
            {
                sudoku[7][jj] = sudoku_digit; //to store the eighth row
                //to store blocks as 2d array
                if(jj<3) block_array[6][jj+3] = sudoku_digit; //store the second three elements in block 7
                else if(jj<6) block_array[7][jj] = sudoku_digit; //store the second three elements in block 8
                else block_array[8][jj-3] = sudoku_digit; //store the first second elements in block 9
                //
                jj++;
                if(jj == 9) jj=0; //we make j =0 at the end to use it at the next row in the next loop of (else if)
            }else if(kk>87 && kk<97)
            {
                sudoku[8][jj] = sudoku_digit; //to store the ninth row
                //to store blocks as 2d array
                if(jj<3) block_array[6][jj+6] = sudoku_digit; //store the third three elements in block 7
                else if(jj<6) block_array[7][jj+3] = sudoku_digit; //store the third three elements in block 8
                else block_array[8][jj] = sudoku_digit; //store the third three elements in block 9
                //
                jj++;
            }
        }
        //checking the solution
        int count_r=0; //for counting existing of element in a row every single loop
        int count_c=0; //for counting existing of element in a column every single loop
        int count_b=0; //for counting existing of element in a block every single loop
        int k, i, j; // for (for loops) parameters
        for(k=1; k<=9; k++) //loop for generating numbers from 1 to 9 to make the checking process
        {
            for(i=0; i<9; i++) //loop for passing through every row
            {
                for(j=0; j<9; j++) //loop for passing through every column
                {
                    //rows checking
                    if(sudoku[i][j] == k) count_r++; //loop for checking if at most that one number from 1 to 9 is existing in a row
                    //columns checking
                    if(sudoku[j][i] == k) count_c++; //loop for checking if at most that one number from 1 to 9 is existing in a column
                    //blocks checking
                    if(block_array[i][j] == k) count_b++; //loop for checking if at most that one number from 1 to 9 is existing in a block
                }
            //finding if there is mistakes in the solution
            if(count_r == 1) count_r = 0; //if count equals 1, that means the element of k is existing only one time so we will make count equals 0 for the next row
            else wrong_count++; // if not, the solution is wrong
            if(count_c == 1) count_c = 0; //if count equals 1, that means the element of k is existing only one time so we will make count equals 0 for the next column
            else wrong_count++;  // if not, the solution is wrong
            if(count_b == 1) count_b = 0; //if count equals 1, that means the element of k is existing only one time so we will make count equals 0 for the next column
            else wrong_count++;  // if not, the solution is wrong
            }
        }
    }
    //printing the sudoku solution
    for(int i=0; i<9; i++)
    {
        printf("\n");
        for(int j=0;j<9; j++)
        {
            printf("%d",sudoku[i][j]);
        }
    }
    //the final message
    if(wrong_count == 0) printf("\n\nThis solution is right.");
    else printf("\n\nThis solution is wrong.");
    //return
    return 0;
}
