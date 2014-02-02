Number Write
============
Given a positive number integer, compute the written text for the number. Number can be from 0 - 10,000,000,000,000 (10 trillion)




Approach
========
First step is to read 3 digits at a time and break it up into single digits. By using the helper function "ThousandWriter" it will write out the text. I then proceed breaking down the problem recursively by having each thousand as one level.

##Induction
####Base cases
Number=0,Level=0 -> return "Zero"
Number=0 -> return ""

####Inductive Step
Append the current string from "ThousandWriter" to the result of the recursion.





Results
=======

Below are some results:

1361992721 : One Billion Three Hundred Sixty One Million Nine Hundred Ninety Two Thousand Seven Hundred Twenty One

113492884 : One Hundred Thirteen Million Four Hundred Ninety Two Thousand Eight Hundred Eighty Four

437334182 : Four Hundred Thirty Seven Million Three Hundred Thirty Four Thousand One Hundred Eighty Two

