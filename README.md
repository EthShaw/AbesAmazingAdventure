This is a project called "Abe's Amazing Adventure!!"

It was not created by me, but I decided to convert its repository from CVS to
git and maybe update it in the future so that it works on Windows 10 or
something. This project was originally created by gabortorok (Gabor Torok) on
SourceForge (which may be the same person as the GitHub user 
[gabortorok](https://github.com/gabortorok).

Here are links to the original page:

<http://abe.sourceforge.net/> | <https://sourceforge.net/projects/abe/>


-------------------------
Abe's Amazing Adventure!!
-------------------------

Requirements:
-------------------------
-SDL library

How to build it:
-------------------------
Linux:
./autogen.sh
./configure
./make

Windows (cross-compile on linux):
./autogen.sh
./cross-configure
./cross-make clean all
(You may need to: cp abe abe.exe)

You need to install mingw's cross-compiler tools for this to work.
See: http://www.mingw.org/mingwfaq.shtml#faq-cross

How to run it:
-------------------------
./abe

and in fullscreen mode:
./abe -f

on Windows:
abe.exe

Notes:
-------------------------
You can also run: ./abe --help to see some other options.
Abe can in video modes between 320x200 to 800x600. It needs at least a 16bpp mode.
You can do: ./abe -t to see what video modes will run faster in fullscreen mode.

Controls:
---------
This is only a demo, so please excuse the rough edges. 
On the startup screen, hit "SPACE" to run the game, or "ENTER" to run the editor.
In general the keys are:

Game:
arrow keys - move
space - jump
enter - use a balloon
esc - quit

Editor: (to enable the editor set Game.h/GOD_MODE to 1 and re-build)
arrow keys - move
home,end,pageup,pagedown - move around by pages
enter - put down tile
1,2,3 - select layer
del,backspace - clear tile
5,6 - cycle thru tiles
L - load map
S - save map
esc - quit
q,w - make a slide (q-top left, w-bottom right)
q,e - make a rectangle

If you have any comments, email me at cctorok@yahoo.com.

Many thanks for sourceforge for hosting Abe!!. Look for more info at http://abe.sf.net.

