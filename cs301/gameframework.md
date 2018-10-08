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

`receiveInfo()`

protected void initAfterReady() - does nothing by default

**protected abstract void receiveInfo(GameInfo info)** called when player receives info

more notes 10/8

`GameAction` object represents a move in requested form by a player

it is sent to the game and then decided if valid, and then causes the game state to be changed

should have more than one action

`GameAction` object defines only one instance variable, the player who is requesting the action

two methods:

`public GamePlayer getPlayer();`
`public void setPlayer(GamePlayer p);`

`GameAction` subclasses will have instance variables

## Network Play

`LocalGame` should not know what kind of players are playing

warning try to avoid large objects

dont use `static`, it is naughty ;)

`HumanPlayer` has an onTouch method, it should check for the state being null, if i dont have a state then dont draw

## Setting up the players

```java
MainActivity extends GameMainActivity {

}
```
