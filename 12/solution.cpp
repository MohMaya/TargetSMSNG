/*

You are given old touch smartphone numbers having dial pad and calculator app.
Aim: The goal is to type a number on the dial pad.
But as the phone is old, some of the numbers and some operations can’t be touched.
For eg. 2,3,5,9 keys are not responding, i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number
Calculator have 1-9 and +,-,\*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.
You have to find the minimum number of touches required to obtain a number.


Input:

There will be multiple Test cases.Each test case will consist of 4 lines


1) The first line will consist of N, M, O

N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)

M:types of operations supported (+,-,*,/)

O: Max no of touches allowed

2) second line of input contains the digits that are working e.g 0,2,3,4,6.

3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)

4) fourth line contains the number that we want to make .



Output:

Output contains 1 line printing the number of touches required to make the number  


Sample Test Case:

1                   // No of test cases

5 3 5            // N ,M, O

1 2 4 6 0     // digits that are working (total number of digits = N),

1 2 3         // describing operations allowed (1–> ‘+’, 2–> ‘-‘, 3–> ‘*’ , 4–> ‘/’ )(total number is equals to M)

5                 // number we want to make


Answer 3

How 4? 1+4=, “=” is also counted as a touch



2nd Sample Case

3                   // No of Test cases

6 4 5            // N ,M, O

1 2 4 6 9 8  // digits that are working (total number of digits = N),

1 2 3 4        // describing operations allowed (1–> +, 2–> -, 3–> , 4–>/)

91                // number we want to make

6 2 4           // 2nd test case

0 1 3 5 7 9

1 2 4           // +, -, / allowed here

28

5 2 10

1 2 6 7 8

2 3               // -, allowed

981



Output:

2        // 91 can be made by directly entering 91 as 1,9 digits are working, so only 2 operations

5            // 35-7=, other ways are 1+3*7=

9          //62*16-11=


Order of computation will be followed as symbols entered if + comes, it will be computed first
One more example: let’s say 1,4,6,7,8,9 works and +,-,* works.
2,3,5 and / doesn’t work.
If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> ‘1+4=’ that requires 4 operations. 
There could be other ways to make ‘5’.

*/