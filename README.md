# Monty Interpreter

This project is an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack with specific instructions to manipulate it.

## Data Structures

The project uses the following data structures, which are defined in the header file:

### stack_s
```c
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
```
This struct represents a node in a doubly linked list, which is used to implement the stack (or queue). Each node contains an integer value (`n`), a pointer to the previous node (`prev`), and a pointer to the next node (`next`).

### instruction_s
```c
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
This struct associates an opcode with its corresponding function. The `opcode` is a string representing the operation, and `f` is a pointer to the function that executes the operation.

## Compilation & Output

Compile the code using the following command:
```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
- The output of the program should be printed on `stdout`.
- Any error messages should be printed on `stderr`.

## Monty Byte Code Files

Monty byte code files have the `.m` extension. Each line in the file contains an opcode and its argument (if any). The opcode and its argument are separated by one or more spaces. Blank lines and comments (lines starting with `#`) are ignored.

## The Monty Program

The `monty` program runs Monty byte code files. It takes one argument, the path to the file containing the Monty byte code.

### Usage
```sh
$ ./monty file
```

### Error Handling
- If no file is provided or more than one argument is given:
  ```sh
  USAGE: monty file
  ```
- If the file cannot be opened:
  ```sh
  Error: Can't open file <file>
  ```
- If an unknown instruction is encountered:
  ```sh
  L<line_number>: unknown instruction <opcode>
  ```
- If a `malloc` failure occurs:
  ```sh
  Error: malloc failed
  ```

## Task List

1. **push, pall**
   - `push`: Pushes an element to the stack.
   - `pall`: Prints all values on the stack, starting from the top.

2. **pint**
   - Prints the value at the top of the stack.

3. **pop**
   - Removes the top element of the stack.

4. **swap**
   - Swaps the top two elements of the stack.

5. **add**
   - Adds the top two elements of the stack.

6. **nop**
   - Does nothing.

7. **sub**
   - Subtracts the top element from the second top element of the stack.

8. **div**
   - Divides the second top element by the top element of the stack.

9. **mul**
   - Multiplies the top two elements of the stack.

10. **mod**
    - Computes the remainder of the division of the second top element by the top element of the stack.

11. **comments**
    - Supports comments in Monty byte code files. Lines starting with `#` are ignored.

12. **pchar**
    - Prints the character at the top of the stack.

13. **pstr**
    - Prints the string starting from the top of the stack.

14. **rotl**
    - Rotates the stack to the top.

15. **rotr**
    - Rotates the stack to the bottom.

16. **stack, queue**
    - `stack`: Sets the format of the data to a stack (LIFO).
    - `queue`: Sets the format of the data to a queue (FIFO).

17. **Brainf*ck**
    - Write a Brainf*ck script that prints "School", followed by a new line. The script should use Brainf*ck instructions to achieve the desired output.

18. **Add two digits**
    - Reads two digits from the user, adds them together, and prints the result. The sum will always be less than 10.

19. **Multiplication**
    - Reads two digits from the user, multiplies them together, and prints the result. The product will always be less than 10.

20. **Multiplication level up**
    - Reads two digits from the user, multiplies them together, and prints the result followed by a new line.

## Repository

Please refer to the GitHub repository [monty](https://github.com/paschalugwu/monty) for the complete code implementation.
