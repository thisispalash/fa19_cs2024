Palash A.
pa334
CS 2024
ass06

This assignment was an extension to assignment 3. We were to dynamically create the menu so it could be created from the main function. We reduced dependence on "hard coding" by creating a private vector of Menu Item instances. The program functions the same as ass03 but it much more flexible.

We replaced the hard coded enumeration with an Item class that holds the prompt and the title. We also moved the display to this class giving flexibility to incorporate a variety of displays. The Menu class from before now stored a vector of these Items and its functions iterate through this vector for various operations. The functionality of the menu items (ie, what the selections do) is defined in the main file but I suspect, this can be converted to a separate file to increase modularity.

This assignment showed an alternate way of doing a previous assignment. Also learnt how to iterate through vectors. This file is no longer challenging to write thanks to http://www.cs.cornell.edu/courses/cs2024/2019fa/AssignmentGuidelines.pdf