Milestone 3:



The first change I implemented was making it so that the first revealed tile is guaranteed to be safe. This is done by checking to see if the selected tile would be a mine and, if it would be, regenerating the board until the tile is safe. While this isn't a feature in every version of Minesweeper, it is a common one and something that, quite frankly, should have already been present here.



Next, I created a boolean that evaluates if a game would be considered "fair" by checking the percentage of the board that would be mines. As this version of Minesweeper is fully customizable, I felt it would be odd for even the easiest of boards to be counted for wins, and added this as a failsafe, although as of now it has no function beyond a warning due to the score system not yet being implemented.



After that, chording was made possible as part of the reveal function. While the code does feel convoluted, it nevertheless functions properly via listing and checking each visible tile around the cursor then clearing them if the amount of flags in said area is equivalent to the value of the tile selected by the cursor.



Finally, an autoClear function was created that is used to automatically clear all tiles around a 0 (which have been replaced by blank spaces on the visible board). This was done partly due to how code from chording could be easily repurposed to do this and partly to fit in with other versions of Minesweeper, as most of them have a similar function.

