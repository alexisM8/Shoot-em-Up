
# Shoot em' Up 
small game written in C++ using [SFML](https://github.com/SFML/SFML) to do the hard work like **window creation** and **drawing**. This game uses a state based system to accomplish certain things like **main menu**,  **pause**, and **end screen**

## Dependencies
 - [SFML](https://github.com/SFML/SFML)

## Features

 - Main Menu
 - Pause and Resume Capabilites
 - End Title Screen
 - Key Board Controls
 - multi  level support

## How to Play

 - 'a': move space ship left
 - 's': move space ship down
 - 'd': move space ship right
 - 'w': move space ship up
 - 'space': fire missle
 - 'esc': pause game
 - 'enter': make selection

## Build in Xcode

 1. Intall the appropriate version of [SFML](https://github.com/SFML/SFML) for your system
 2. in Xcode create a new project and select command line tool and give a good name to the folder
 3. Navigate to the folder you just created and in the same folder with the **folder_name.xcodeproj** paste the **SFML** folder you downloaded earlier
 4. Open up the project and navigate to the build settings
 5. under the **Header Search Paths** type: **${SRCROOT}/SFML/include**
 6. under the **Library Search Paths** type: **${SRCROOT}/SFML/lib**

## Images
![Main Menu](https://github.com/alexisM8/Shoot-em-Up/blob/main/imgs/main%20menu.png)
![Lvl One](https://github.com/alexisM8/Shoot-em-Up/blob/main/imgs/lvl%201.png)
![Pause Screen](https://github.com/alexisM8/Shoot-em-Up/blob/main/imgs/pause%20screen.png)
![complete lvl](https://github.com/alexisM8/Shoot-em-Up/blob/main/imgs/complete%20level.png)
![lvl two](https://github.com/alexisM8/Shoot-em-Up/blob/main/imgs/lvl%202.png)
