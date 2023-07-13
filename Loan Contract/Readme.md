# Problem Statement
We are giving you a smart contract called MetaCoin, which implements a basic token which the accounts can give to each other with the sendCoin function, and see their balance with the getBalance function. What you have to do is to make a smart contract extending the functionality of the MetaCoin to provide functionality of acting as a loan deposit and settling contract.

There will be an Owner of the Loan contract, and he will have an initial balane of 100K MetaCoins, as in the constructor of the MetaCoin class. Assume that he has accumulated these 100K coins by taking loans. He would store the debt he is in to each creditor in a mapping called loans. You have to implement the following functions along with a constructor and modifier:
1. getCompoundInterest : allows anyone to use it to calculate the amount of interest for given values of P, R, T (in years). Remember that solidity does not have a good support for floats though, so enter the rate as a whole number (like if the rate is 83%, enter 83). We are looking for an iterative implementation to calculate the Compound Interest, which is compounded annually, to test if you understood the applications of loops. This is an inefficient method though, and we'll come back to that later, but we want it to be iterative. A few blogs to clue you in to how to perform percentage based calculations with just integers have been provided in the template.

2. reqLoan: anyone should be able to use it to request the Owner to settle his loan. The P, R, T entered is used to calculate the dues, and is added to a mapping. It should emit the Request event.

3. getOwnerBalance: anyone can use it to get the amount of MetaCoins owned by the owner. make use of MetaCoin contract's getBalance to implement this, to get a taste of inheritance!

4. viewDues : only the owner can access this to view the amount of loan he owes to the input address, which is stored in the loans mapping. Be sure to make use of the modifier!

5. settleDues: only the owner can use this to settle the amount of loan he owes to the input address, use MetaCoin's sendCoin function to settle these dues, with appropriate checks for the return values from sendCoin. Also remember to set the amount owed to 0 or whatever remains if sendCoin runs succesfully!

More instructions (if required) are available in the template.

# Code and Working
Here in this code, "MetaCoin" class was given in the template and "Loan" is the derived class.
"isOwner" is a modifier that allows the function to work only when "msg.sender" is the owner.
"getCompoundInterest" is function that takes principle,rate,time as input and gives the compound interest using "muldiv" function,here the Principal is first 
multiplied by 1e8 and then the final amount to pay is divided by 1e8 to improve precision.

Example
![image](https://user-images.githubusercontent.com/96648258/175776278-29ec4869-225b-477c-a183-2b9e69ed752b.png)

Taking the highlighted account is the owner and the account below that is creditor

"getBalance" function
![image](https://user-images.githubusercontent.com/96648258/175776360-d04afb6b-811a-453e-80cc-7b2f5e189a53.png)

"getOwnerBalance" ![image](https://user-images.githubusercontent.com/96648258/175776463-334bb87a-c702-4d6e-98e1-1a0093455578.png)

"reqloan" and "viewDues" ![image](https://user-images.githubusercontent.com/96648258/175776601-7fbe0fba-56fb-48b2-b7f5-1af994e58c2f.png)

after using "settleDues","getOwnerBalance","viewDues" and "getBalance"
![image](https://user-images.githubusercontent.com/96648258/175776760-e70e08a8-c26e-407f-bbd6-43ef46449ea1.png)




