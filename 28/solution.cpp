/*

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


*/