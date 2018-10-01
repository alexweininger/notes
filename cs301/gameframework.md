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

