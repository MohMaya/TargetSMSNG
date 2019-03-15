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

#include <iostream>

using namespace std;
#define lim 10000

int ctr=0, nNodes=0;
int bracketPairs[lim/2][2];
int verbose=0;

class Queue{
public:
    int arr[lim], level[lim];
    int front, end, num_elements;
    Queue(){
        front=0;
        end=0;
        num_elements=0;
        for(int i=0; i<lim; i++){
            arr[i]=-1;
            level[i]=-1;
        }
    }

    bool isEmpty(){
        if(num_elements==0)
            return true;
        else
            return false;
    }

    void enqueue(int x, int l){
        level[end]=l;
        arr[end++]=x;
        num_elements++;
    }

    int dequeue(){
        int retval = arr[front++];
        num_elements--;
        return retval;
    }

    int dequeue2(){
        return level[front];
    }

    void printQ(){
        cout<<"\nQUEUE IS : ";
        for(int i=front; i<end; i++)
            cout<<arr[i]<<"\t";
        cout<<endl;
    }
};


class Stack{
public:
    int arr[lim];
    int top, num_elements;
    Stack(){
        top=0;
        num_elements=0;
        for(int i=0; i<lim; i++)
            arr[i]=-1;
    }
    void push(int c){
        arr[top++]=c;
        num_elements++;
    }

    int peek(){
        return arr[top-1];
    }

    int pop(){
        int temp = arr[top-1];
        top--;
        num_elements--;
        return temp;
    }

    bool isEmpty(){
        if(num_elements==0)
            return true;
        else
            return false;
    }
};


void treeParser(char parsedTree[], string tree, int from, int to, int ind_to_insert){
    if(verbose){
        cout<<"\nFROM : "<<from<<"\tTO : "<<to<<"\tIND_TO_INS : "<<ind_to_insert;
    }
    nNodes+=1;
    if(to-from == 1){
        //Empty Node
        parsedTree[ind_to_insert]=' ';
        if(verbose)
            cout<<"\t ROOT = \' \'\n";
        return;
    }
    char root=tree[from+1];
    if(verbose)
        cout<<"\t ROOT  = "<<root<<endl;
    parsedTree[ind_to_insert]=root;
    int left_begin=from+2;
    int left_end=0;
    for(int i=0; i<ctr; i++){
        if(bracketPairs[i][0]==from+2){
            left_end=bracketPairs[i][1];
        }
    }

    int right_begin=left_end+1;
    int right_end=to-1;
    treeParser(parsedTree, tree, left_begin, left_end, 2*ind_to_insert+1);
    treeParser(parsedTree, tree, right_begin, right_end, 2*ind_to_insert+2);
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        int k;
        string tree;
        cin>>k>>tree;
        if(verbose){
            cout<<"\n*******************************************************************\n";
            for(int i=0; i<tree.length(); i++)
                cout<<i<<" : "<<tree[i]<<"\n";
            cout<<"\n*******************************************************************\n";
        }
        if(tree=="()"){
            cout<<0;
            continue;
        }
        char parsedTree[lim];
        ctr=0;
        Stack st;
        for(int i=0; i<tree.length(); i++){
            if(tree[i]=='(')
                st.push(i);
            if(tree[i]==')'){
                bracketPairs[ctr][0]=st.pop();
                bracketPairs[ctr++][1]=i;
            }
        }
        treeParser(parsedTree, tree, 0, tree.length()-1, 0);

        if(verbose){
            for(int i=0; i<nNodes; i++){
                cout<<parsedTree[i]<<"    ";
            }
            cout<<endl;
        }
        int parsedTreeValue[lim][2];
        for(int i=0; i<nNodes; i++){
            if(parsedTree[i]==' ')
                parsedTreeValue[i][0]=-1;
            else
                parsedTreeValue[i][0] = parsedTree[i]-'0';
        }
        int l;
        parsedTreeValue[0][1]=0;
        for(int i=0; i<nNodes; i++){
            parsedTreeValue[2*i+1][1]=parsedTreeValue[i][1]+1;
            parsedTreeValue[2*i+2][1]=parsedTreeValue[i][1]+1;
        }

        if(verbose){
            cout<<"\nFINAL TREEEEEEEEEEEEEEEEEEEE"<<endl;
            for(int i=0; i<nNodes; i++)
                cout<<parsedTreeValue[i][0]<<"\t";
            cout<<endl;
            for(int i=0; i<nNodes; i++)
                cout<<parsedTreeValue[i][1]<<"\t";
            cout<<endl;
        }

        int sum=0;
        for(int i=0; i<nNodes; i++){
            if(parsedTreeValue[i][0]==-1)
                continue;
            if(parsedTreeValue[i][1]==k)
                sum+=parsedTreeValue[i][0];
        }

        cout<<sum;

    }
}
