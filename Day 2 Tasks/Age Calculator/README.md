# Age Calculator App

## Description
This Age Calculator program calculates the age of a user based on their birth date and the current date. The program accounts for leap years and validates the input for correct dates. It outputs the user's age in years, months, and days.

## Features
- Calculates the user's age based on their birth date and the current date (set to 22nd October 2023 in the code).
- Accounts for leap years when calculating the number of days in February.
- Validates input to ensure the birth date is within a valid range and matches the correct format.

## How to Use

1. **Open the Project:**
   - Open the project in Code::Blocks by selecting the `.cbp` file.
   
2. **Build and Run:**
   - Click on the "Build" and then "Run" options in the Code::Blocks IDE.

3. **Program Workflow:**
   - The program will prompt you to enter your birth date in the format `DD-MM-YYYY`.
   - Make sure to enter a valid date (e.g., between the years 1980 and Current).
   - The program will calculate and display your age in years, months, and days.

## Example Output
```
------------------------Age Calculator App------------------------ 

Enter Your Birth Date in the format "DD-MM-YYYY": 15-08-2000 

Your age is: 24 years, 0 months, and 19 days
```

## Requirements
- Code::Blocks IDE
- C compiler (included with Code::Blocks)

## Additional Information
  - The current date is hardcoded as 3rd September 2024. You can modify the C_DD, C_MM, and C_YY variables in the code to change the current date.
  - The program checks for leap years and validates the number of days in each month before calculating the age.
