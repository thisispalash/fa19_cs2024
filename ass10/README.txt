Palash A.
pa334
CS 2024
ass10

This assignment built on ass09. I was unable to finish the previous assignment on time. The error that I was unable to figure out turned out to be a missing flag to the compiler indicating that it should use c++11 standards.

This assignment provides almost entire functionality of the bank. The only things left are security and inter account transfers. The use of map made searching accounts easier, less lines of code. An invalid account number kept bringing segmentation fault until I explicitly checked for the validity of the account number.

`Menu` and related classes are unchanged from the previous assignment. The majority of the changes are made to the `Bank` class. We now store a selected current account for account ops. Also, duplicate account numbers are not allowed to avoid conflicts.

Fun assignment again. Really starting to enjoy these. One suggestion would be allow for makefiles. Typing the massive line with all the files gets cumbersome. Besides, makefile knowledge is good knowledge to have.