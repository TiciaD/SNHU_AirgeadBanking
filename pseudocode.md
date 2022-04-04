## Functionality
Create a compound interest calculator taking user input of:
  - Initial Investment Amount
  - Monthly Deposit
  - Annual Interest
  - Number of years 

Then returning two static reports of year-end balances and year-end earned interest based on those user inputs.

## Things to Keep in Mind
- Given Number of Years by the user, this must be converted to months for the calculation
- Interest Calculation = (Opening Amount + Deposited Amount) * ((Interest Rate / 100) / 12)

## Variables
`Initial Investment Amount` (Opening Amount) --> starting amount of investment (positive real number)  
`Monthly Deposit` (Deposited Amount) --> monthly contribution to investment (positive real number)  
`Annual Interest` (Compounded) --> Interest / 100 for decimal (positive float)  
`Number of Years` --> Number of years investment has to grow (positive real number)

## Methods
`readNumber()` --> takes in a prompt, returns prompt to console and reads value from user input 

`printReport()` --> calls calculation function, prints results from calculation to console in correct format

`calculateBalance()` --> takes in initialAmount, monthlyDeposit, interest and years and performs calculation to determine year-end balance

`getMonthlyInterest()` --> calculates monthly interest based on years given

## Classes
```
Console
- readNumber(prompt)
  - send string that contains prompt for user
  - returns value of user input
```
```
Report
- printReport()
```
```
BalanceCalculator
- calculateBalance(initialAmount, monthlyDeposit, interest, years)
```

## Brief Workflow Overview
```
START

PROMPT user for initial investment amount
  WHILE wait for user input
    IF user input == int
      break
    ELSE
      send error message and continue loop
    ENDIF
  ENDWHILE

(repeat for monthly deposit, annual interest, number of years)

GET balance

DISPLAY year-end report

END

```
