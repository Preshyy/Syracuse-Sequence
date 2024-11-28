# SYRACUSE SEQUENCE SIMULATOR
A C++ program that simulates the Syracuse (Collatz) sequence for integer, decimal, and negative inputs. The program includes user-friendly menus for ease of access, sequence visualization as a way to understand this phenomenon with the numbers used,
and tracking functionality to keep track of the number of moves it takes to reach the 4-2-1 loop.

## Features
- Collatz Sequence Calculation: A function that computes the Syracuse sequence for various input types:
  - With even numbers: Divides the number by 2.
  - With odd numbers: Multiplies the number by 3 and adds 1.
- Input Types: Accepts normal integers, decimal numbers, and negative numbers.
  - The conjecture only works for all normal integers. Adding decimal and negative numbers was an additional experimental feature that served as a way to play around with the logic.
- User Menu: A user menu defined in the main function. It exists to guide the user to select a desired input type, enabling a smooth user-experience.
- Sequence Visualization: A function that displays the entire sequence once computed.
- Move Counter: A Boolean function that tracks the number of steps to reach 1. 
- "4-2-1" Loop Check: Verifies if the sequence ends in the classic 4-2-1 loop.

## Functions
- collatz_sequence(double n, vector<double>& sequence)
  - Calculates the Collatz sequence for a given number n.
  - Appends each step to the sequence vector.
  - Increments the moves counter.
- visualize_sequence(const vector<double>& sequence)
  - Displays the entire sequence to the console.
- ends_in_421(const vector<double>& sequence)
  - Returns true if the sequence ends in the 4-2-1 loop.

## Key Concepts
- Data Types:
  - long double: To handle large and precise starting numbers.
  - vector<double>: To store the generated sequence dynamically.
  - string: Used for user input, later converted to numeric values, to handle long strings of numbers.
- String Conversion:
  - stoi: Converts a string to an integer.
  - stod: Converts a string to a double, supporting decimal and negative values.
- Error Handling:
  - try-catch: Ensures invalid input does not crash the program.
- Loops:
  - do-while: Allows reusability for generating multiple sequences.
