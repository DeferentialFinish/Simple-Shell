# Simple CLI
C++ Shell framework for a general purpose command line. Overly commented
for easy use by others and simple structure for easy adoption.


## Uses
- Providing a drop down shell for maintainance
- Interactive Tooling

## Issues
  - There is an issue where if a command is supplied with spaces
    the program will output two prompts as if it recieved two
    inputs.
  - Only entering the return charicter will not return the prompt 
    again but instead drops cursor onto a blank line.
