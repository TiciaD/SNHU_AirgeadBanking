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

## Brief Workflow Overview
```
