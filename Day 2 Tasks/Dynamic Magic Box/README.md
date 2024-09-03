
# Box Drawing App

## Description
This Box Drawing App prompts the user to input an odd number between 3 and 19, which determines the size of a box. The program then draws a box on the console screen, displaying numbers in a pattern that fills the box.

## Features
- Allows the user to specify the size of the box (an odd number between 3 and 19).
- Dynamically adjusts the console cursor position to create a box pattern.
- Displays numbers in a spiral pattern within the box.

## How to Use

1. **Open the Project:**
   - Open the project in Code::Blocks by selecting the `.cbp` file.

2. **Build and Run:**
   - Click on the "Build" and then "Run" options in the Code::Blocks IDE.

3. **Program Workflow:**
   - The program will prompt you to enter the box size, which should be an odd number between 3 and 19.
   - After entering the valid size, the console will clear, and the box will be drawn with numbers in a spiral pattern.
   - The program will reset the cursor position after drawing the box.

## Example Output

```
Enter the Box size "Odd Number Between(3~19)": 5
     
             15 8  1  24 17
             16 14 7  5  23
             22 20 13 6  4
             3  21 19 12 10
             9  2  25 18 11
```



## Requirements
- Code::Blocks IDE
- C compiler (included with Code::Blocks)
- Windows OS (required for the `windows.h` library)

## Additional Information
- The program uses the `gotoxy()` function to move the cursor around the console window. This function is specific to Windows systems, so the program may not work on other operating systems.
- If the user enters an invalid size, the program will repeatedly prompt them until a valid size is entered.
- The box size is limited to odd numbers between 3 and 19 due to the size constraints of the console window.

