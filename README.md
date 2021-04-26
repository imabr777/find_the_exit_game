# Find the Exit Game
By Abraham Im

## Description
This is a simple little C++ game where you play as the little @ symbol, and you have to move him to the exit, marked by the O. Somewhat reminiscent of Snake, only the game ends once you hit the goal.

The game first asks where it should place the exit, between ints 1 and 25 (it doesn't check whether the input is in the bounds). After the player inputs the coordinates, it draws the board and waits for the arrow keys to be pressed.

The game is won when the @ symbol reaches the O exit. At this point, the game asks the player if they want to play again.

It does keep track of the @'s position and stops it when it reaches the boundaries.

## Notes
This helped me learn about the `switch` structure, as well as writing a function and taking keyboard input using `<conio.h>`.

I found something odd, which is that when I press an arrow key, C++ registers two hits, one from 224, and the other from the regular arrow key number. I have no idea why this is, but I've figured out that calling `_getch()` twice, and utilizing the value from the second call does the trick. 

The idea for this game came to me randomly and I had to try it right away. Did not come from a tutorial, although I wouldn't be too surprised if something like this existed somewhere.