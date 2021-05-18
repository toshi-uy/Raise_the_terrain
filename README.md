<h1 align="center"> Raise the Terrain
<img src="https://i.imgur.com/WLnRkBJ.png"
width=100% alt="title">

###  Optional task working with SDL2 to create 3D projections (intro to game programming) using C programming language and SDL libraries

<img src="https://i.imgur.com/fzp4Slr.mp4"
width=50% alt="rotation">

## Introduction
This is an optional task in my Holberton Software Developer Foundations Course I'm taking. The first trick is to install the SDL2 libraries to your computer, I used macOS and xCode to code all the files in C programming language. Then just compile it with the correct flags and run it in an environment with video enabled (I runned it on Mac's terminal, but you can use a vagrant environment with video enabled it. I'll leave you this tutorial to do so: https://rleons.medium.com/how-to-use-sdl2-library-in-a-vagrant-environment-ccd8d8872e78).

To do this task there weren't too much resources, I watched a couple of videos on Youtube and followed some tutorials from http://lazyfoo.net/tutorials/SDL/index.php

## Previous steps and Compilation
First of all you will have to clone this repository:

    $ git clone https://github.com/toshi-uy/Raise_the_terrain.git

To compile the file first you need to run the script install_sdl2.sh to install SDL libraries:

    Raise_the_terrain$  chmod 755 install_sdl2.sh
    Raise_the_terrain$ ./install_sdl2.sh

If everything was OK, you will get:

    ...
    All set!    
    
    Don't forget to compile with: `sdl2-config --cflags`  
    Don't forget to link with: `sdl2-config --libs` -lSDL2_ttf  
    SDL2$

Then just compile using the flags shown here (or use the compiled file of the repo):

    Raise_the_terrain$    gcc -ffast-math -Wall -Werror -Wextra -pedantic -c -frounding-math -funsafe-math-optimizations -fno-builtin *.c `sdl2-config --cflags`
    Raise_the_terrain$    gcc *.o `sdl2-config --libs --static-libs` -o draw

And run the program with your altitude file:

    Raise_the_terrain$  ./draw test

The program needs a \<file> that contains the grid altitudes and the same grid altitudes are the ones that sets the grid rows and columns. For example you can save the files as terrain1 with the altitudes:

    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00
    
This will create a 10 x 10 grid all flat (11 dots are 10 boxes):

<img src="https://i.imgur.com/OEZUckR.png" width="400px">

Or try the one in our task:
the following altitudes,

```
120 60 40 60 20 -20 -80 -120
40 20 30 30 -10 -40 -90 -110
20 30 10 06 -6 -20 -26 -90
00 -6 10 10 -6 -20 -20 -40
-20 -20 -18 -14 -40 -20 -20 -30
-10 -10 -10 -10 -8 -20 -20 -30
20 10 10 10 10 04 10 -10
30 24 24 22 20 18 14 16
```
the grid should look like this:

<img src="https://i.imgur.com/HMPbl98.png" width="400px">

I challenge you to use different altitude and create your own grids! Have fun!!

## How does it work?

-   It reads a file "example"
-   It generates a window
-   Gets the coordinates of each point from the file
-   You can rotates the grid, when the user press the keys LEFT, RIGHT
-   Finish program when the user presses ESC key or with Quit button

## Controls
- ESC - Closes the window
- LEFT - Rotates grid left
- RIGHT - Rotates grid left

## Bugs
Not known bugs, if you want to report a bug just write me and I'll look at it.
## Author
[**Toshi Borgia**](https://github.com/toshi-uy)
