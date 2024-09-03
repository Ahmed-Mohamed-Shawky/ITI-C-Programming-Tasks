# Calculator App

## Description
This Calculator App allows users to perform basic arithmetic operations such as addition, subtraction, multiplication, and division. The program takes an equation in the form of `X+Y` and outputs the result. It continues to run in a loop until the user chooses to exit.

## Features
- Supports basic arithmetic operations: addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
- Validates division to prevent dividing by zero.
- Allows users to continue using the calculator until they choose to exit.

## How to Use

1. **Open the Project:**
   - Open the project in Code::Blocks by selecting the `.cbp` file.

2. **Build and Run:**
   - Click on the "Build" and then "Run" options in the Code::Blocks IDE.

3. **Program Workflow:**
   - The program will prompt you to enter an equation in the format `X+Y`, where `X` and `Y` are numbers, and `+` is the operation.
   - After entering the equation, the program will display the result.
   - The program will ask if you want to exit; enter `Y` or `y` to exit, or any other key to continue.

## Example Output

```
------------------------Calculator App------------------------

Enter your equation with this form 'X+Y': 5.2+3.7

5.20 + 3.70 = 8.900

Do you want to Exit?? Y/N ? n

*-*-*-*-*-*-*-* Do u like it :D *-*-*-*-*-*-*-*-*

Enter your equation with this form 'X+Y': 10/2

10.00 / 2.00 = 5.000

Do you want to Exit?? Y/N ? Y
```

## Requirements
- Code::Blocks IDE
- C compiler (included with Code::Blocks)

## Additional Information
- The program handles division by zero by printing an error message if the user attempts to divide by zero.
- You can modify the `Num_1` and `Num_2` variables in the code for different default values if needed.

