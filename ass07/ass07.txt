Palash A.
pa334
CS 2024
ass07

This assignment was an extension to assignment 6. We essentially overloaded the << operator to display the Menu or a menu Item. The rest of the functionality is the same. The prints within the overloaded functions are modified however for aesthetics.

This assignment turned out to be quite frustrating. The return type of the op-function was to be `ostream` and not the class it was in. Then, I ran into some problems as I had defined a `const` variable in one function and not that in the other one. This took me quite a while to figure out. I understood the bug when I was trying to print all possible information (old school ftw!). On trying to append the output of `getPrompt` method in the `Item` class to `ostream` resulted in an error telling me that the function was not marked const. I then looked for the variables marked const and removed it (to make them truly variable).

This assignment was fun, mostly due to the successful debugging. However, I do realize that this assignment would have been easier (for me) if I had not marked anything const because everything in the program is variable until instantiated in the main function. Looking forward to next week!
