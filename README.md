# Stack Machine

A console-based stack machine simulator written in C. It demonstrates how a **LIFO (last in, first out)** stack works and how arithmetic and logic can be done by operating on the top of a stack.

## Features

- Push one or many values
- Pop the top value, print the top, display the whole stack with indexes
- Arithmetic on chosen stack positions: add, subtract, multiply, divide
- Logic operations: AND, OR, NOT
- Stack overflow and underflow detection (fixed capacity of 100 values)

## Menu

```
1. Push Value(s)     5. Multiply (Custom) 9. Logical NOT (Custom)
2. Pop Top Value     6. Divide (Custom)   10. Print Top
3. Add (Custom)      7. AND (Custom)      11. Display Stack
4. Subtract (Custom) 8. OR (Custom)       12. Exit
```

## Build and run

```bash
gcc "stack machine/main.c" -o stack_machine
./stack_machine
```

On Windows, open `stack machine/stack machine.cbp` in Code::Blocks and press Build and Run.

## Concepts practised

Arrays as stacks, `switch` menus, pointers to the top index, input handling with `scanf`, error handling for empty and full stacks.

## Author

Tawhid Hossain, [@tawhid011](https://github.com/tawhid011)
