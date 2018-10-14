# TargetSMSNG

Questions:

1.  Given an array of numbers, find whether a particular digit exist in the numbers of array.
2.  A binary matrix of n X m, you have to toggle any column k number of times so that you can get maximum rows having all 1.
3.  Given a graph having edges defining the probability of going to a particular node, say edge u-v denotes the probability of going v from u. you can stay at any node for 10 minutes. Starting from node 1, on which node you will be after T minutes and with what probability.
4.  Find a cycle, if exists, in a directed graph. If there is none, print 0. If there is one, print the path starting from the first node of the cycle to the last. If there are more than one, print any path.
5.  It was a combination of Rat in a Maze and longest subpath problem.
6.  Find if given graph is bipartite or not, if it is bipartite then print either white color nodes or black color nodes.
7.  Find a cycle in the graph.
8.  Find a cycle in LinkedList.
9.  Variation of traveling salesman solved using backtracking (Optimization on traveling salesman ).
10. You’ll be given a grid as below:
    ```
    0 1 0 2 0

    0 2 2 2 1

    0 2 1 1 1

    1 0 1 0 0

    0 0 1 2 2

    1 1 0 0 1

    x x S x x
    ```
    In the grid above,
    1: This cell has a coin.
    2: This cell has an enemy.
    0: It contains nothing.
    The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
    Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
    At each time, the non-highlighted part of the grid will move down by one unit.
    We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
    If we use a bomb at the very beginning, the grid will look like this:
    ```
    0 1 0 2 0

    0 0 0 0 1

    0 0 1 1 1

    1 0 1 0 0

    0 0 1 0 0

    1 1 0 0 1

    x x S x x
    ```
    As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
    For example,
    At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin( coins=2).
    After this, remain at the same position( coins=4).
    This is the current situation after collecting 4 coins.
    ```
    0 1 0 2 0 0 1 0 0 0

    0 2 2 2 1 -->after using 0 0 0 0 1

    x x S x x -->bomb x x S x x

    Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
    ```
11. Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of a (the) shortest path.
You don’t have to solve this problem efficiently. You could find an answer by looking up all the possible ways. If you can look up all the possibilities well, you will get a perfect score.
<strong>Constraints</strong>
5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.
[Input]
You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.
<strong>Output</strong>
Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.
<strong>I/O Example</strong>
Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively, and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)
  ```
  5 ← Starting test case #1

  0 0 100 100 70 40 30 10 10 5 90 70 50 20
  6 ← Starting test case #2

  88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14


  10 ← Starting test case #3

  39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
  ```
  Output (10 lines in total)  
  ```
  #1 200

  #2 304

  #3 366

  ...
  ```
12. You are given old touch smartphone numbers having dial pad and calculator app.
Aim: The goal is to type a number on the dial pad.
But as the phone is old, some of the numbers and some operations can’t be touched.
For eg. 2,3,5,9 keys are not responding, i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number
Calculator have 1-9 and +,-,\*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.
You have to find the minimum number of touches required to obtain a number.
Input:
  ```
  There will be multiple Test cases.Each test case will consist of 4 lines


  1) The first line will consist of N, M, O

  N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)

  M:types of operations supported (+,-,*,/)

  O: Max no of touches allowed

  2) second line of input contains the digits that are working e.g 0,2,3,4,6.

  3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)

  4) fourth line contains the number that we want to make .
  ```
Output:
  ```
  Output contains 1 line printing the number of touches required to make the number  
  ```
  ```
  Sample Test Case:

  1                   // No of test cases

  5 3 5            // N ,M, O

  1 2 4 6 0     // digits that are working (total number of digits = N),

  1 2 3         // describing operations allowed (1–> ‘+’, 2–> ‘-‘, 3–> ‘*’ , 4–> ‘/’ )(total number is equals to M)

  5                 // number we want to make


  Answer 3
  ```
  How 4? 1+4=, “=” is also counted as a touch
  ```
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
  ```
Order of computation will be followed as symbols entered if + comes, it will be computed first
One more example: let’s say 1,4,6,7,8,9 works and +,-,* works.
2,3,5 and / doesn’t work.
If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> ‘1+4=’ that requires 4 operations. There could be other ways to make ‘5’.

13. There is one spaceship. X and Y coordinate of source of spaceship and destination spaceship is given. There are N number of wormholes each wormhole has 5 values. First 2 values are starting co-ordinate of wormhole and after that value no. 3 and 4 represents ending co-ordinate of wormhole and last 5th value is represents cost to pass through this wormhole. Now these wormholes are bi-direction.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. It is ok if you wont use any wormhole.
Hint:
You can make graph which contain edge between all points and put cost of that edge. Now apply dijstra algorithm to find minimum distance between source to destination co-ordinate of spaceship.
Here the main catch is that the cost to pass through wormhole can be zero so you have to take care while making graph matrix.

14. There is an island surrounded by oil mines. You will be given n companies and m oil mines having values. You have to distribute the mines to “n” companies in a fair manner. Remember the companies can have oil mines adjacent to each other and not in between of each other. After distributing them compute the difference of oil mines from the company getting highest and company getting lowest. This number should be minimum.(then only the distribution can be termed as fair).
```
Input
2
2 4
6 13 10 2
2 4
6 10 13 2

Output
5
1
```

15.  A delivery boy wants to deliver some items on his way from office to home. You need to find the optimized path he should take from office to home and deliver all his deliveries on his way. It is 101 X 101 grid. Office, home , delivery points are represented via coordinated (x,y) where 0 <= x <= 100, 0 <= y <= 100. Distance between two points (x1, y1) and (x2,y2) is computed as |x1 – x2| + |y1 – y2| .You need to find the optimized path from office to home covering all delivery locations and return the optimized path length as output. You will be given the input in the 2 lines.
```
First Line – N (no. of delivery locations)

Second Line – (x,y) coordinates of office, followed by home, followed by all N delivery locations.

3
0 0 100 100 20 30 50 50 70 70

output: The length of the optimized path taken.

For above input, the output is 200
```
16. There are N pots. Every pot has some water in it. They may be partially filled. Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow. The crow knows O1 to On(overflow no. for all the pots). Crow wants some K pots to be overflow. So the task is the minimum number of stones he can make K pots overflow in the worst case.
```
An array of overflow no--. {1,...On}
Number of pots--n
No of pots to overflow-- k
```
Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1). So crow will put 5 stones in the pot with overflow no.(58), it will not overflow, then he will put them in the pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.
What is the best algorithm to do it?
17. Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
```
Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] –> [3,5,8] –> [3,8] –> [8] –> [] coins = 3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167
```
