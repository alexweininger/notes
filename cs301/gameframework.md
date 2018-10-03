# Game Framework

local game: initiates game stand and passes it to the player

	uses game state

player: received game state and initializes game action object and passes it to local game

	uses game action

The MainActivity interacts with the user to specify the names of the players in the game.

At most one may be a GameHumanPlayer per tablet.

Gives gui control to the player with setAsGui()

there is a start method for each player

**initAfterReady()** initializing method, gui, data, etc.

String **checkIfGameOver()** returns null if not over, non-null string means game is over

protected void BsendUpdatedStateTo(GamePlayer p); sends game state object to a particular player

protected boolean **canMove(int playerIdx)**

protected boolean **makeMove(GameAction action)**

## Computer Player

main wait loop waits to receive a message

**receiveInfo()**

protected void initAfterReady() - does nothing by default

**protected abstract void receiveInfo(GameInfo info)** called when player receives info

