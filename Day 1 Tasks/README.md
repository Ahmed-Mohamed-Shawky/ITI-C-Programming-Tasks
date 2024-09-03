# Integer to Binary Conversion Program

## Description
This program is part of a Code::Blocks project that converts an integer into its binary representation and also displays the number in decimal, hexadecimal, and octal formats. Additionally, it displays the ASCII value of a user-input character and prints the memory addresses of the entered integer and character.

## Features
- Converts an integer to binary using two different methods (`int_to_bin` and `int_to_bin_v2`).
- Displays the number in decimal, hexadecimal, and octal formats.
- Displays the binary equivalent of the number.
- Displays the ASCII value of a user-input character.
- Shows the memory addresses of the integer and character variables.

## How to Use
1. **Open the Project:**
   - Open the project in Code::Blocks by selecting the `.cbp` file.
   
2. **Build and Run:**
   - Click on the "Build" and then "Run" options in the Code::Blocks IDE.

3. **Program Workflow:**
   - The program prompts the user to enter an integer.
   - The entered number is then printed in decimal, hexadecimal, octal, and binary formats.
   - The program prompts the user to enter a character.
   - The ASCII value of the character is displayed along with the memory addresses of the integer and character variables.

## Example Output

```
Hello world!
------------------------------
Enter any Number u want: 13
The Number u Entered is: 13 	 dec 
                         d 	 Hexa 
                         15 	 oct 
                         1101 	 binary
------------------------------
Enter any character u want: A
The character u Entered is: A and its ASCII is: 65
------------------------------
The int variable 'num' address in memory is: 342148621
The char variable 'ch' address in memory is: 342148620
```

## Requirements
- Code::Blocks IDE
- C compiler (included with Code::Blocks)

## Additional Information
- This project uses two different methods for converting an integer to binary: 
  - `int_to_bin`: Iterative method.
  - `int_to_bin_v2`: Recursive method.
- The memory addresses printed by the program will vary depending on your system's architecture.
