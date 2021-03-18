# STACK

A stack is an Abstract Data Type (ADT), is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).



![stack](https://media.giphy.com/media/KDYB0cH4HW8xc3VIAx/source.gif)



Operations in stack

1.Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.

2.Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.

3.Peek or Top: Returns top element of stack.

4.isEmpty: Returns true if stack is empty, else false.

Features of stack 

1. Dynamic data structures
2. Do not have a fixed size
3. Do not consume a fixed amount of memory


# Push Operation

Step 1 − Checks if the stack is full.


Step 2 − If the stack is full, produces an error and exit.

Step 3 − If the stack is not full, increments top to point next empty space.

Step 4 − Adds data element to the stack location, where top is pointing.

Step 5 − Returns success.


Algorithm for PUSH Operation

if stack is full

return null

endif top ← top + 1

stack[top] ← data

end procedure


# Pop Operation

Step 1 − Checks if the stack is empty.

Step 2 − If the stack is empty, produces an error and exit.

Step 3 − If the stack is not empty, accesses the data element at which top is pointing.

Step 4 − Decreases the value of top by 1.

Step 5 − Returns success.

Algorithm for Pop Operation

stack if stack is empty return null

endif data ← stack[top]

top ← top – 1

return data

end procedure

