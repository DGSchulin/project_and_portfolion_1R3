Milestone 4:



The first main addition was that of the Keeper class, being added by itself first before eventual implementation into Minesweeper.



Next, I made adjustments to how flags functioned in order to prevent players from accidentally revealing a flagged tile, as well as adding the ability to unflag a tile by trying to flag a flagged tile. Alongside this, a few changes were made to how boards with a size of ten or greater were printed; these were remnants of larger changes I attempted to make to board printing as a whole in order to make it more aesthetically pleasing. Said changes ultimately fell through when I recognized that implementing these changes would also further limit the maximum possible board size.



After that, I implemented the Keeper class into Minesweeper. There isn't much to say on this matter, although it did finally give the fairGame boolean a proper use.



Finally, I chose to add more statistics to be kept track of, those being the amount of games played, the amount of games lost, and the amount of tiles revealed. These new stats did make me revise preexisting parts of Keeper and Game to facilitate implementation, with the most notable of said changes being the conversion of reveal() and autoClear()'s return types from void to int in order to get the amount of times addTile() would need to be called in Minesweeper.

