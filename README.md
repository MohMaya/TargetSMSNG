# Target SAMSUNG Research Institute

### Question 1 :  [DONE]


You are given an unsorted array with both positive and negative elements. You have to find the smallest positive number missing from the array in O(n) time using constant extra space.

**Input:** First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

**Output:** Single line output, print the smallest positive number missing.

**Constraints:**

1<=T<=100 and 1<=N<=100

**Example:**
```
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2
```

### Question 2 : [DONE]


A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum number of rows having all 1’s.

```
for eg, n=3, m=3,

1 0 0

1 0 1

1 0 0
if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there is 1 row with all 1’s.
```

**Constraints :**

N ≤ 20 and M ≤ 10^5

### Question 3 : [DONE]

> [Redundant. Refer : Question 32]


### Question 4 : [DONE]

Find a cycle, if exists, in a directed graph. If there is none, print 0. If there is one, print the path starting from the first node of the cycle to the last. If there are more than one, print any path.

### Question 5 :

It was a combination of Rat in a Maze and longest subpath problem.

### Question 6 :    [DONE]

Find if given graph is bipartite or not, if it is bipartite then print either white color nodes or black color nodes.

### Question 7 :    [DONE]

Find a cycle in the graph.
> [Refer Question 4]

### Question 8 :

Find a cycle in LinkedList.

### Question 9 : [DONE]

Variation of traveling salesman solved using backtracking (Optimization on traveling salesman ).
> [Refer Question 11]

### Question 10 :   [DONE]

You’ll be given a grid as below:

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
```
Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.


### Question 11 : [DONE]

Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities. You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of a (the) shortest path. You don’t have to solve this problem efficiently. You could find an answer by looking up all the possible ways. If you can look up all the possibilities well, you will get a perfect score.

**Constraints: **

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.

**Input:**

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.

**Output:**

Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.

**I/O Example:**

Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively, and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)

```
5 ← Starting test case #1
0 0 100 100 70 40 30 10 10 5 90 70 50 20

6 ← Starting test case #2
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
.
.
.
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

### Question 12 :

You are given old touch smartphone numbers having dial pad and calculator app. Aim: The goal is to type a number on the dial pad. But as the phone is old, some of the numbers and some operations can’t be touched. For eg. 2,3,5,9 keys are not responding, i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number. Calculator have 1-9 and +,-,\*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it. You have to find the minimum number of touches required to obtain a number.

**Input:**

```
There will be multiple Test cases.Each test case will consist of 4 lines

1) The first line will consist of N, M, O
	N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
	M:types of operations supported (+,-,*,/)
	O: Max no of touches allowed

2) Second line of input contains the digits that are working e.g 0,2,3,4,6.

3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)

4) Fourth line contains the number that we want to make .
```

**Output:**

```
Output contains 1 line printing the number of touches required to make the number
```

**Sample Test Case:**
```
1                   // No of test cases
5 3 5            // N ,M, O
1 2 4 6 0     // digits that are working (total number of digits = N),
1 2 3         // describing operations allowed (1–> ‘+’, 2–> ‘-‘, 3–> ‘*’ , 4–> ‘/’ )(total number is equals to M)
5                 // number we want to make

Output:
3

How 4? 1+4=, “=” is also counted as a touch
```
**2nd Sample Case :**
```
3                   // No of Test cases
6 4 5            // N ,M, O
1 2 4 6 9 8  // digits that are working (total number of digits = N),
1 2 3 4        // describing operations allowed (1–> +, 2–> -, 3–> , 4–>/)
91                // number we want to make
6 3 5           // 2nd test case
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
Order of computation will be followed as symbols entered if + comes, it will be computed first.

*One more example*: let’s say 1,4,6,7,8,9 works and +,-,* works. 2,3,5 and / doesn’t work.
If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> ‘1+4=’ that requires 4 operations. There could be other ways to make ‘5’.

### Question 13 :   [DONE]

There is one spaceship. X and Y coordinate of source and destination of spaceship are given. There are N number of wormholes each wormhole has 5 values. First 2 values are starting co-ordinate of wormhole and after that value no. 3 and 4 represents ending co-ordinate of wormhole and last 5th value is represents cost to pass through this wormhole. These wormholes are bi-directional.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
Find minimum distance to reach spaceship from source to destination co-ordinate using any number of worm-hole. It is ok if you wont use any wormhole.
**Hint:**
You can make graph which contain edge between all points and put cost of that edge. Now apply djikstra algorithm to find minimum distance between source to destination co-ordinate of spaceship. Here the main catch is that the cost to pass through wormhole can be zero so you have to take care while making graph matrix.

### Question 14 :   [DONE]

There is an island surrounded by oil mines. You will be given n companies and m oil mines having values. You have to distribute the mines to “n” companies in a fair manner. Remember the companies can have oil mines adjacent to each other but not in between of each other. After distributing them compute the difference of oil mines from the company getting highest and company getting lowest. This number should be minimum.(then only the distribution can be termed as fair).

```
Input
2			-Num Of Test Cases
2 4			- N(companies), M(oil mines)
6 13 10 2	- Oil value of each mine
2 4
6 10 13 2

Output
5			- Company1:  +	   Company2:   +   =>   -  =5
1			- Company1: 6+10   Comapny2: 13+2  => 16-15=1
```

### Question 15 : [DONE]

> [Refer Question 11]

A delivery boy wants to deliver some items on his way from office to home. You need to find the optimized path he should take from office to home and deliver all his deliveries on his way. It is 101 X 101 grid. Office, home , delivery points are represented via coordinated (x,y) where 0 <= x <= 100, 0 <= y <= 100. Distance between two points (x1, y1) and (x2,y2) is computed as |x1 – x2| + |y1 – y2| .You need to find the optimized path from office to home covering all delivery locations and return the optimized path length as output. You will be given the input in the 2 lines.

```
First Line – N (no. of delivery locations)

Second Line – (x,y) coordinates of office, followed by home, followed by all N delivery locations.

3
0 0 100 100 20 30 50 50 70 70

output: The length of the optimized path taken.

For above input, the output is 200
```

### Question 16 :

There are N pots. Every pot has some water in it. They may be partially filled. Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow. The crow knows O1 to On(overflow no. for all the pots). Crow wants some K pots to be overflow. So the task is the minimum number of stones he can make K pots overflow in the worst case.

```
An array of overflow no--. {1,...On}
Number of pots--n
No of pots to overflow-- k
```

Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1). So crow will put 5 stones in the pot with overflow no.(58), it will not overflow, then he will put them in the pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.
What is the best algorithm to do it?

### Question 17 :   [DONE]

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
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

### Question 18 :

Dijkstra code.

### Question 19 :

Kahn’s algorithm.

### Question 20 :

Topological Sort.

### Question 21 :

How to implement a stack using BST

### Question 22 :

Write a program to convert char\* mac_address to int array.
Eg: mac_address ="ab : cd : ef : 12 : 34 : 56" to
result= [ab, cd, ef, 12,34,56]

### Question 23 :

Write a MergeSort for Two Different Sorted Link List… Emphasis on TO and SO with all Error Conditions..

### Question 24 :   [DONE]

Stock Buy Sell to Maximize Profit

### Question 25 :   [DONE]

Next greater number set digits

### Question 26 :

Smallest Positive missing number
> [Refer Question 1]

### Question 27 :

Kadane’s Algorithm

### Question 28 :   [DONE]

Given an integer ‘K’ and a tree in string format. We had to print the sum of all elements at Kth level from root.
For example:-

```
        0
    /     \
  5         7
/    \      /   \
6       4    1     3
\
9
```

Tree was given in the form: (node value(left subtree)(right subtree))

For tree given above: (0(5(6()())(4()(9()())))(7(1()())(3()())))

Input format: K Tree

Output format: Sum

For example, for given tree:

Input: 2 (0(5(6()())(4()(9()())))(7(1()())(3()())))

Output: 14

### Question 29 :

A company sells its products with a unique serial number on it. Company has has found that there are some products that don’t sell well which are identified to have ominous numbers in the serial number of the product. So if a serial number of the product contains atmost ’k’ ominous number then it won’t sell.Given a range form s to e, you need to find number of products that would sell, leaving out the products that contains atmost ’k’ ominous numbers.

Input: First line contains the number of test cases, followed buy the range s to e, 1

### Question 30 : [DONE]

A Research team want to establish a research center in a region where they found some rare-elements. They want to make it closest to all the rare-elements as close as possible so that they can reduce overall cost of research over there. It is given that all the rare-element’s location is connected by roads. It is also given that Research Center can only be build on road. Team decided to assign this task to a coder. If you feel you have that much potential..
Here is the Task :- Find the shortest of the longest distance of research center from given locations of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road..
Number of rare-element and their location was also given(number<=5)
and order of square matrix was less than equal to (20).

### Question 31 : [DONE]

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and the edge weights are the probabilities of the doctor going from that division to other connected division but the doctor stays 10mins at each division now there will be given time and had to find the division in which he will be staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling time is not considered and during that 10min at 10th min he will be in next division, so be careful.

### Question 32 :   [DONE]

Fishing Spots: 1 to N
3 Gates with gate position and number of fishermen waiting to get in
Distance between consecutive spots = distance between gate and nearest spot = 1 m.
Fishermen are waiting at the gates to get in and occupy nearest fishing spot. Only 1 gate can be opened at a time and all fishermen of that gate must occupy spots before next gate is open.
There could be 2 spots closest to the gate. Assign only 1 spot to the last fisherman in such a way that we get minimum walking distance. For rest of the fishermen, ignore and assign any one.
Write a program to return sum of minimum distance need to walk for fishermen.
Note : The problem can be solved using Recursion and Backtracking by considering all possible combinations.

### Question 33 : [DONE]

Given a string, your task is to find the number of patterns of form 1[0]1 where [0] represents any number of zeroes (minimum requirement is one 0) there should not be any other character except 0 in the [0] sequence.

**Input:**

The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string.

**Output:**

For each test case, output the number of patterns.

**Constraints:**

1<=T<=20

1<=Length of String<=2000

**Example:**
```
Input:
2
100001abc101
1001ab010abc01001

Output:
2
2
```

### Question 34 : [DONE]

You are given a pointer/reference to a node to be deleted in a linked list. The task is to delete the node.  Pointer/reference to head node is not given.  You may assume that the node to be deleted is not the last node.

**Input:**

You have to complete a method which takes one argument: pointer/reference to a node to be deleted.  There are multiple test cases. For each test case, this method will be called individually.


**Example:**
```
Input :
2
2
1 2
1
4
10 20 4 30
20

Output :
2
10 4 30
```

### Question 35 : [DONE]

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

**Input:**
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case contains an integer N denoting the no of elements in BST. Then in the next line are N space separated values of the BST. The third line of each test case contains an integer k for k largest element.

**Output:**
Print the kth largest element in each line.

**Constraints:**
1<=T<=20 ; 1<=N ; K<=20


**Example(To be used only for expected output):**
```
Input:
1
7
50 30 20 40 70 60 80
3

Output:
60
```
### Question 36 : [DONE]

Company S has developed an industrial endoscope available to explore inner part of the decrepit water pipes.
It is possible to explore the inner part of the pipes putting the endoscope in a certain part of the pipe.
The endoscope can be moved in the pipe only. Meanwhile, when the pipes are connected to each other, if the length of the endoscope is long enough to explore ,then it is able to inspect the connected pipes. However, we cannot observe every pipe because the length of endoscope is limited.

When the map of the ground water pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of pipe which are available to explore. Length of endoscope means the range upto which endoscope can explore. There are seven kind of pipes, and description for each pipe are shown below:


| S.No | Pipe           | Connected to  |
| -----|:-------------: | -------------:|
| 1    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/1.png ) | Up, Down, Left, Right |
| 2    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/2.png ) | Up, Down              |
| 3    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/3.png ) | Left, Right           |
| 4    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/4.png ) | Up, Right             |
| 5    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/5.png ) | Down, Right           |
| 6    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/6.png ) | Down, Left            |
| 7    | ![](https://github.com/rishabh115/InterviewQuestions/raw/master/Samsung/res/7.png ) | Up, Left              |

When the map of the ground water pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of pipe which are available to explore. Length of endoscope means the range upto which endoscope can explore.

**Input**

In the first line, T, the number of total test cases is given. From the second line, T test cases are given. In the first line of each test case, N, the height of the map of the ground water pipes, M, the width, R, the vertical location of the water pipe where to put in the endoscope, C, the horizontal location of it, and the length of the endoscope L are given. In the following N lines information of the map of ground water pipe is given. Each line has M numbers. Each number (from 1 to 7) means the type of water pipe for that point. 0 means there is no water pipe buried in that place.

**Output**

Print the respective answer for T test cases in total for T lines. The answer is the number of water pipes which is available to  observe using the endoscope.

**Constraints**
1≤ T ≤100 ; 1≤ N, M ≤50 ; 0≤ X < N ; 0≤ Y < M ; 1≤ L ≤ 20

### Question 37 : [DONE]

Men's restroom problem : It is a well-researched fact that men in a restroom generally prefer to maximize their distance from already occupied stalls, by occupying the middle of the longest sequence of unoccupied places. For detailed version, check the following link. <br>
Link : https://stackoverflow.com/questions/32645046/urinal-algorithm-a-simple-optimization


