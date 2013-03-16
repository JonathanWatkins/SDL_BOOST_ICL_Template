SDL_BOOST_ICL_Template
=========

This is a template for a C++ project compiled with cmake/nmake on windows that includes Boost/SDL and is compiled with Intel ICL for windows

Installation
============

You will need the SDL.dll in the same directory as the executable, otherwise you will get a run-time error.


On Windows
----------

To compile with cmake. Run

cmake . -G "NMake Makefiles"

Then 

nmake

Notes
=====
These are some notes on configuring icl on windows.


C:\WINDOWS\system32\cmd.exe /E:ON /V:ON /K ""C:\Program Files (x86)\Intel\Composer XE 2013\bin\iclvars.bat" intel64"


move iclvars.bat to bin dir

//bootstrap.bat

//b2 toolset=intel --type=complete


To compile with boost

icl /EHsc meshworks.cpp /I c:\boost /link /LIBPATH:c:\boost\lib

To compile with boost and sdl and opengl

icl /EHsc /MD meshworks.cpp /I c:\boost_1_51_0\ /I c:\SDL-1.2.15\include\ /I c:\SDL_ttf-2.0.11\include\  /link /LIBPATH:c:\boost_1_51_0\lib c:\SDL-1.2.15\lib\x64\SDLmain.lib c:\SDL-1.2.15\lib\x64\SDL.lib c:\SDL_ttf-2.0.11\lib\x64\SDL_ttf.lib c:\SDL-1.2.15\lib\x64\sdlgfx.lib opengl32.lib glu32.lib /SUBSYSTEM:CONSOLE


