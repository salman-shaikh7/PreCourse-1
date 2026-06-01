// Time Complexity: O(1)
/*
All operations (push, pop, peek, isEmpty) execute in constant time.
- For a stack size of 10: each operation takes the same steps
- For a stack size of 1000: each operation takes the same steps

Since the number of operations does not increase with the input size,
the time complexity is O(1).
*/

// Space Complexity: O(N)
/*
Where N = MAX capacity (1000)

The array is allocated at compile-time with a fixed size (MAX).
Regardless of how many elements are pushed,
the total memory reserved remains constant at N = 1000 integers.

Therefore, space complexity is O(N) where N is the capacity.
*/



// Did this code successfully run on Leetcode :
/*
I did not find this problem on leetcode
*/ 



// Any problem you faced while coding this :

/*
1. Syntax implmentation 
2. Thinking about edge case
3. Understanding of what is expected of each function push pop
4. Error Handling approch

*/


// Your code here along with comments explaining your approach

/*
Approach:
1. I started with the base template provided in the assignment,
   which gave me the class structure and method signatures.

2. I understood the data storage mechanism:
   - Use a fixed-size array (int array[MAX]) to store stack elements
   - Use an index variable (index_of_top_element) to track the position of the top

3. I implemented each method based on the LIFO principle:
   - push(): Increment index and store the element at that position
   - pop(): Return element at current index and decrement index
   - peek(): Return element at current index without modifying index
   - isEmpty(): Check if index equals -1 (empty state)

4. I added error handling to prevent overflow and underflow:
   - Check if index reaches MAX-1 before pushing (overflow)
   - Check if index is -1 before popping/peeking (underflow)
   - Return INT_MIN to signal errors to the caller

5. For the main() function test cases, I used an LLM to generate
   comprehensive test scenarios covering:
   - Underflow conditions (pop/peek on empty stack)
   - Normal push/pop operations
   - Overflow conditions (filling the stack to capacity)
   - Edge cases (popping all elements until empty)
*/




#include <bits/stdc++.h> 
  
using namespace std; 
  
#define MAX 1000 
  
class Stack {
    int index_of_top_element; 
  
public: 
    int array[MAX]; // Maximum size of Stack 
  
    Stack() { index_of_top_element = -1;} 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{

    if (index_of_top_element == MAX-1)
    {
        return false;
    }
    else
    {   
        index_of_top_element = index_of_top_element + 1;
        array[index_of_top_element]= x;
        return true;
    }

} 
//[0,2,3]
  
int Stack::pop() 
{ 

    if (index_of_top_element == -1)
    {
        cerr << "Stack Underflow\n";
        return INT_MIN;
    }
    else
    {   
        int top_value = array[index_of_top_element];
        index_of_top_element = index_of_top_element -1 ;
        return top_value;
    }


} 

int Stack::peek() 
{ 
    if (index_of_top_element < 0) 
    {
        cerr << "Stack is empty\n";
        return INT_MIN;
    }
    return array[index_of_top_element];
} 
  
bool Stack::isEmpty() 
{ 
    if (index_of_top_element == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
} 
  
int main() 
{ 
    Stack s;

    cout << "--- Testing Underflow ---" << endl;
    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Peeking empty stack: " << s.peek() << endl;
    cout << "Popping empty stack: " << s.pop() << endl;

    cout << "\n--- Testing Normal Operations ---" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stacked: 10, 20, 30" << endl;
    cout << "Top element (peek): " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "New Top: " << s.peek() << endl;

    cout << "\n--- Testing Overflow ---" << endl;
    cout << "Pushing until full (MAX=" << MAX << ")..." << endl;
    // We already have 2 elements (10, 20). Fill the rest.
    for (int i = 0; i < MAX - 2; i++) {
        if (!s.push(i)) {
            cout << "Push failed unexpectedly at i=" << i << endl;
        }
    }
    
    cout << "Current Top: " << s.peek() << endl;
    cout << "Attempting to push one more (MAX+1)..." << endl;
    if (!s.push(9999)) {
        cout << "Success: Stack Overflow detected!" << endl;
    } else {
        cout << "Failure: Stack Overflow NOT detected!" << endl;
    }

    cout << "\n--- Final Underflow Test ---" << endl;
    cout << "Popping all elements..." << endl;
    while (!s.isEmpty()) {
        s.pop();
    }
    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Popping once more: " << s.pop() << endl;

    return 0; 
}