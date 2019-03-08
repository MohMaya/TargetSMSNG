/*

There are N pots. Every pot has some water in it. 
They may be partially filled. 
Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow.
The crow knows O1 to On(overflow no. for all the pots). Crow wants some K pots to be overflow. 
So the task is the minimum number of stones he can make K pots overflow in the worst case.

An array of overflow no--. {1,...On}
Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1). 
So crow will put 5 stones in the pot with overflow no.(58), it will not overflow, then he will put them in the pot with overflow no.(5), 
hence the total no. of stones to make overflow one pot is=10.
What is the best algorithm to do it?

*/