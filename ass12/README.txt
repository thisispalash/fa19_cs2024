Palash A.
pa334
CS 2024
ass12

This assignment was an extension of ass11. We were to change all Bank related pointers to smart pointers to better manage memory and prevent leaks. Initially, there were a lot of errors when I tried to pass around `weak_ptr`s. I was forced to change everything to a `shared_ptr` except the current account. Another issue I ran into was file updating. Initially I did not pad all elements and eventually, they were being overwritten. Hence, added padding. Lastly, I added header guards in all the files to protect from multiple definitions. 

As for bank features, I record the transactions as every bank does. A ton of error checking is also added so that invalid accounts cannot be selected. Privacy is added as well so that only the currect account can see their balance when listing all account.

Looking back at the assignments, this was the most fun. Perhaps because I added new features. Other than that, had fun in this course and also learnt new Cpp things! Thank you!