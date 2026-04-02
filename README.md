# SiegeSmasher
Third Person Multiplayer Tower Defense Demo.
Developed in Unreal Engine 5. Coded in C++ by a team of three, myself included.
Has a LAN implementation for the multiplayer but there is a branch with a WIP version using Steam’s multiplayer service.
Allows for up to 4 players to play at one time on 4 different machines.

Gameplay Demonstration:
[![Watch the Demo](https://github.com/user-attachments/assets/50abd308-8c58-4bca-8cb3-9c4e55685b5c)](https://drive.google.com/file/d/1EHXPOIMH9tWux6rCrVsQgR2O4HTc3kpd/view?usp=sharing)

# Features:


### Enemies (My Contribution) -

Three different Enemy types. Controlled by behaviour tree's with custom nodes that I implemented. 


Vampire - The most basic enemy that has the sole objective of reaching the end of the level. If a player does get in his way he attacks them with his sword dealing damage. The sphere in the picture is a componenet of the path finding, it is invisible in the actual game.

<img width="409" height="329" alt="image" src="https://github.com/user-attachments/assets/1ffcf305-63c1-447b-a450-39773720e60c" />
<img width="1469" height="844" alt="image" src="https://github.com/user-attachments/assets/70310c72-ccb1-478a-9b4e-03f3b0fe707f" />



Demon - The tank of the game. Has high health but slow walk speed, he ignores the players but decides to help the other enemies out by destroying the towers the players put down.

<img width="200" height="384" alt="image" src="https://github.com/user-attachments/assets/a51d955e-7185-4cb7-b581-742b4bf85819" />
<img width="1500" height="754" alt="image" src="https://github.com/user-attachments/assets/85b4c901-6915-4740-801e-d4006551d6f1" />


Witch - The healer of the game. Heals the enemies from the damage the players deal but also heavily focusses on trying to kill the players with her homing fireball spell.


<img width="471" height="376" alt="image" src="https://github.com/user-attachments/assets/adfdd753-122b-4aff-9756-a7e9662bd878" />
<img width="1500" height="608" alt="image" src="https://github.com/user-attachments/assets/4d048226-e01b-4671-b944-877cb2757ff6" />


Code Snippet of how their path finding works - 

<img width="1500" height="412" alt="image" src="https://github.com/user-attachments/assets/d35d833c-d88c-4a0b-b422-fdac776bd56d" />



### Player -
The player is able to shoot an arrow from the bow that you see to kill enemies. The power of the arrow is determined by how long the player holds the mouse down for, which is indicated in the UI.
They have player animations which use multiple blendspaces and a state machine to switch between blend spaces.


<img width="499" height="537" alt="image" src="https://github.com/user-attachments/assets/6c0920b6-aeef-44b0-9fee-cba6266f4680" /> <img width="386" height="286" alt="image" src="https://github.com/user-attachments/assets/3f7df566-0c32-480d-870c-07992c630efa" />

### Leaderboard and Towers-

Damaging and killing enemies gives points that are used to buy more towers to place ,which you saw in the video, and on the leaderboard to see who is doing the best.

<img width="1429" height="844" alt="image" src="https://github.com/user-attachments/assets/9b4dcd76-4b06-4904-903a-986f2921b615" />


