Palash A.
pa334
CS 2024
ass08

This assignment explores polymorphism and implements a menu based system using abstract base classes. The MenuItem can either be a MenuCommand or a Menu itself. Both the classes implement the derived virtual `select` and `display` methods. The `display` method simply displays the option, while the `select` method provides the main functionality. For the Menu, it displays the menu and prompts the user for a selection. For a Command, it currently just displays the command selected. 

This assignment was relatively easy, however tedious. The only part the gave trouble was the constructer for the abstract class and how to implement that. Other than that, the assignment comprised of simple I/O. I have also added functionality for detecting an invalid choice as the program would just display the menu again. The explicit output informs the user that the user has made a mistake and the program is correct.

Aesthetically, I like how `main.cpp` is looking now. Menu and MenuCommand need a little more work. Finally, menus could be stored read dynamically instead of being declared in `main`. This was a fun assignment as well. Keep 'em coming!