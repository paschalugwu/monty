# Monty Interpreter

This project is an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack with specific instructions to manipulate it.

## Data Structures

The project uses the following data structures, which are defined in the header file:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

The code will be compiled using the following command:
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
The output of the program should be printed on  `stdout` , and any error messages should be printed on  `stderr` .

## Monty Byte Code Files

Monty byte code files have the  `.m`  extension. Each line in the file contains an opcode and its argument (if any). The opcode and its argument are separated by one or more spaces. Blank lines and comments (lines starting with  `#` ) are ignored.

## The Monty Program

The  `monty`  program is used to run Monty byte code files. It takes one argument, which is the path to the file containing the Monty byte code.

If the user does not provide any file or provides more than one argument, the program will print the error message  `USAGE: monty file`  and exit with status  `EXIT_FAILURE` .

If the file cannot be opened, the program will print the error message  `Error: Can't open file <file>`  and exit with status  `EXIT_FAILURE` .

If the file contains an unknown instruction, the program will print the error message  `L<line_number>: unknown instruction <opcode>`  and exit with status  `EXIT_FAILURE` .

If the program encounters a  `malloc`  failure, it will print the error message  `Error: malloc failed`  and exit with status  `EXIT_FAILURE` .

## Task List

1. **push, pall**: Implement the  push  opcode, which pushes an element to the stack, and the  pall  opcode, which prints all the values on the stack. The  push  opcode takes an integer argument and adds it to the stack. The  pall  opcode prints all the values on the stack, starting from the top.

2. **pint**: Implement the  pint  opcode, which prints the value at the top of the stack. It retrieves the top element of the stack and prints it, followed by a new line.

3. **pop**: Implement the  pop  opcode, which removes the top element of the stack. It removes the top element from the stack, and if the stack is empty, it prints an error message.

4. **swap**: Implement the  swap  opcode, which swaps the top two elements of the stack. It swaps the positions of the top two elements in the stack.

5. **add**: Implement the  add  opcode, which adds the top two elements of the stack. It retrieves the top two elements from the stack, adds them together, and stores the result in the second top element.

6. **nop**: Implement the  nop  opcode, which does nothing. It is used as a placeholder or for alignment purposes.

7. **sub**: Implement the  sub  opcode, which subtracts the top element of the stack from the second top element. It retrieves the top two elements from the stack, subtracts the top element from the second top element, and stores the result in the second top element.

8. **div**: Implement the  div  opcode, which divides the second top element of the stack by the top element. It retrieves the top two elements from the stack, divides the second top element by the top element, and stores the result in the second top element.

9. **mul**: Implement the  mul  opcode, which multiplies the top two elements of the stack. It retrieves the top two elements from the stack, multiplies them together, and stores the result in the second top element.

10. **mod**: Implement the  mod  opcode, which computes the remainder of the division of the second top element of the stack by the top element. It retrieves the top two elements from the stack, performs the modulo operation, and stores the result in the second top element.

11. **comments**: Implement support for comments in the Monty byte code files. Any line in the file that starts with a  #  character should be treated as a comment and ignored.

12. **pchar**: Implement the  pchar  opcode, which prints the character at the top of the stack. It retrieves the top element from the stack and treats it as an ASCII value to print the corresponding character.

13. **pstr**: Implement the  pstr  opcode, which prints the string starting from the top of the stack. It retrieves each element from the stack and treats it as an ASCII value to print the corresponding characters until it reaches a value of 0 or encounters an invalid ASCII value.

14. **rotl**: Implement the  rotl  opcode, which rotates the stack to the top. It moves the top element of the stack to the bottom, and the second top element becomes the new top.

15. **rotr**: Implement the  rotr  opcode, which rotates the stack to the bottom. It moves the bottom element of the stack to the top, and all other elements shift down by one position.

16. **stack, queue**: Implement the  stack  and  queue  opcodes, which set the format of the data to either a stack (LIFO) or a queue (FIFO). The  stack  opcode sets the format to stack mode, and the  queue  opcode sets the format to queue mode. In stack mode, the top of the stack is the front of the queue, and in queue mode, the front of the queue is the top of the stack.

17. **Brainf*ck**: Write a Brainf*ck script that prints the word "School", followed by a new line. Brainf*ck is an esoteric programming language, and the script should use Brainf*ck instructions to achieve the desired output.

Let's understand this task better:
A. The task requires you to write a Brainf*ck script that prints the word "School" followed by a new line. The Brainf*ck script should be stored in the  `bf`  subdirectory. You can use the  `bf`  interpreter to test your code.

B. Here is a step-by-step explanation of the code:
-[--->+<]>--.-[------>+<]>.+++++.+++++++..---.>++++++++++.
- The Brainf*ck script uses a series of Brainf*ck commands to generate the desired output.
- Each Brainf*ck command is represented by a single character and performs a specific operation.
- Let's break down the script line by line:
-[--->+<]>--
- This line initializes the first cell of the memory to hold the ASCII value of the letter 'S' (83).
- It uses a series of decrement ( `-` ) and increment ( `+` ) commands to set the value of the first cell.
.-[------>+<]>.
- This line prints the letter 'S' by using the  `.`  command, which outputs the ASCII value of the current cell.
- The value of the first cell is 83, which corresponds to the letter 'S'.
+++++.+++++++..
- This line initializes the second cell of the memory to hold the ASCII value of the letter 'c' (99).
- It uses a series of increment ( `+` ) commands to set the value of the second cell.
---.
- This line prints the letter 'c' by using the  `.`  command.
- The value of the second cell is 99, which corresponds to the letter 'c'.
>++++++++++.
- This line initializes the third cell of the memory to hold the ASCII value of the letter 'h' (104).
- It uses a series of increment ( `+` ) commands to set the value of the third cell.
>++++++++++.
- This line initializes the fourth cell of the memory to hold the ASCII value of the letter 'o' (111).
- It uses a series of increment ( `+` ) commands to set the value of the fourth cell.
>++++++++++.
- This line initializes the fifth cell of the memory to hold the ASCII value of the letter 'o' (111).
- It uses a series of increment ( `+` ) commands to set the value of the fifth cell.
---.
- This line prints the letter 'o' by using the  `.`  command.
- The value of the fifth cell is 111, which corresponds to the letter 'o'.
>++++++++++.
- This line initializes the sixth cell of the memory to hold the ASCII value of the letter 'l' (108).
- It uses a series of increment ( `+` ) commands to set the value of the sixth cell.
-.>++++++++++.
- This line prints the letter 'l' by using the  `.`  command.
- The value of the sixth cell is 108, which corresponds to the letter 'l'.
>++++++++++.
- This line initializes the seventh cell of the memory to hold the ASCII value of the letter '!' (33).
- It uses a series of increment ( `+` ) commands to set the value of the seventh cell.
.
- This line prints the exclamation mark '!' by using the  `.`  command.
- The value of the seventh cell is 33, which corresponds to the exclamation mark '!'.

The resulting output of the Brainf*ck script is "School" followed by a new line.

18. **Add two digits**: Read two digits from the user and add them together. The program should prompt the user to enter two digits, read the input, add the digits together, and print the result.

A. The task requires you to write an efficient Brainf*ck script that adds two digits given by the user. The script should read the two digits from stdin, add them together, and print the result. The total of the two digits will always be one digit-long, meaning it will be less than 10.

B. Here is a step-by-step explanation of the code:
```brainfuck
>,
>,
<
[->+<]
++++++++
[
>------
<-
]
>.
```
-  `>,`  reads the first digit from stdin and stores it in the first memory cell.
-  `>,`  reads the second digit from stdin and stores it in the second memory cell.
-  `<`  moves the memory pointer back to the first memory cell.
-  `[->+<]`  subtracts the value in the first memory cell from the second memory cell and stores the result in the second memory cell. This effectively adds the two digits together.
-  `++++++++`  adds 8 to the second memory cell, which corresponds to adjusting the ASCII value to print the correct character.
-  `[
  >------
  <-
  ]`  subtracts 7 from the second memory cell, which adjusts the ASCII value back to the correct range for printing.
-  `>.`  outputs the result, which is the sum of the two digits.

Please note that Brainf*ck is a minimalistic language and the code provided is already quite efficient for the given task.

19. **Multiplication**: Read two digits from the user and multiply them together. The program should prompt the user to enter two digits, read the input, multiply the digits together, and print the result.

A. The task requires you to write an efficient Brainf*ck script that multiplies two digits given by the user. The script should read the two digits from stdin, multiply them together, and print the result. The result of the multiplication will always be one digit-long, meaning it will be less than 10.

B. Here is a step-by-step explanation of the code:
```brainfuck
>,
>,
>++++++++
[
    <------
    >-
]
++++++++
[
    <<------
    >>-
]
<<
[
    >
    [
        >+
        >+
        <<-
    ]
    >>
    [
        -
        <<+
        >>
    ]
    <
    [-<<<+>>>]
    <<-
]
++++++++
[
    <++++++
    >-
]
<.
```

-  `>,`  reads the first digit from stdin and stores it in the first memory cell.
-  `>,`  reads the second digit from stdin and stores it in the second memory cell.
-  `>++++++++`  initializes the third memory cell with the value 8, which will be used for multiplication.
-  `[
  <------
  >-
  ]`  multiplies the first and second digits together using a loop. It subtracts 1 from the first memory cell and adds the value in the third memory cell to the second memory cell until the first memory cell becomes 0.
-  `++++++++`  adds 8 to the second memory cell, which corresponds to adjusting the ASCII value to print the correct character.
-  `[
  <<------
  >>-
  ]`  subtracts 7 from the second memory cell, which adjusts the ASCII value back to the correct range for printing.
-  `<<`  moves the memory pointer back to the first memory cell.
-  `[
  >
  [
      >+
      >+
      <<-
  ]
  >>
  [
      -
      <<+
      >>
  ]
  <
  [-<<<+>>>]
  <<-
  ]`  multiplies the first and second digits together using nested loops. It adds the value in the third memory cell to the first and second memory cells, shifting the result to the left. It then subtracts 1 from the first memory cell and adds the value in the third memory cell to the second memory cell until the first memory cell becomes 0.
-  `++++++++`  adds 6 to the first memory cell, which corresponds to adjusting the ASCII value to print the correct character.
-  `[
  <++++++
  >-
  ]`  subtracts 7 from the first memory cell, which adjusts the ASCII value back to the correct range for printing.
-  `<.`  outputs the result, which is the product of the two digits.

20. **Multiplication level up**: Read two digits from the user, multiply them together, and print the result, followed by a new line. The program should prompt the user to enter two digits, read the input, multiply the digits together, and print the result with a new line.

A. The task requires you to write an efficient Brainf*ck script that multiplies two digits given by the user. The script should read the two digits from stdin, multiply them together, and print the result followed by a new line.

B. Here is a step-by-step explanation of the code:
```brainfuck
,>,>++++++[-<--------<-------->>]<<[->[->+>+<<]>[-<+>]<<]>[-]>+>[->+<<<<+>>>]>[<<[-]+>>>[-]++++++++++<[->-[>]<<]<[-<<---------->>>>>>>+<<<<<]<[-<]>>>]>>>[-<<<<<<+>>>>>>]<<[-]<<<++++++[-<++++++++<++++++++>>]<.[-]<.[-]>>>>>>>>>>>++++++++++.
```
-  `,>,`  reads the first and second digits from stdin and stores them in the first and second memory cells.
-  `>++++++[-<--------<-------->>]`  initializes the third memory cell with the value 6, which will be used for multiplication.
-  `<<[->[->+>+<<]>[-<+>]<<]`  multiplies the first and second digits together using nested loops. It adds the value in the third memory cell to the first memory cell and duplicates the value in the second memory cell. It subtracts 1 from the first memory cell and adds the value in the third memory cell to the second memory cell until the first memory cell becomes 0.
-  `>[-]>+>[->+<<<<+>>>]`  moves to the fourth memory cell and adds the value in the second memory cell to it.
-  `>[<<[-]+>>>[-]++++++++++<[->-[>]<<]<[-<<---------->>>>>>>+<<<<<]<[-<]>>>]`  moves to the fifth memory cell and multiplies it by the value in the fourth memory cell using nested loops. It adds the value in the fourth memory cell to the fifth memory cell and duplicates the value in the fifth memory cell. It subtracts 1 from the fourth memory cell and adds the value in the fourth memory cell to the fifth memory cell until the fourth memory cell becomes 0.
-  `>>>[-<<<<<<+>>>>>>]<<[-]`  moves to the sixth memory cell and adds the value in the fifth memory cell to it.
-  `<<<++++++[-<++++++++<++++++++>>]`  moves back to the first memory cell and adds 10 to it to adjust the ASCII value for printing.
-  `<.[-]`  prints the result from the first memory cell and clears it.
-  `<.[-]`  prints a new line character and clears the second memory cell.
-  `>>>>>>>>>>>++++++++++.`  moves to the eleventh memory cell and prints a period character.

Please refer to the GitHub repository [monty](https://github.com/paschalugwu/monty) for the complete code implementation.
