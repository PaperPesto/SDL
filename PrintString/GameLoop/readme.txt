Configurazione progetto
-----------------------

-> Target Build x64

-> Creare main.cpp

Proprietà Progetto
-> Configuration settings
	-> C/C++
		-> General
		-> Additional include directory
		=> SDL2/include

	-> Linker
		-> General
			-> Additional library directories
			=> SDL2/lib/x64
		-> Input
			-> Additional dependencies
			=> SDL2.lib
			=> SDL2main.lib
		-> System
			-> SubSystem
			=> Console (/SUBSYSTEM:CONSOLE)

-> Copiare SDL2/lib/x64/SDL2.dll nella main root del progetto (dove c'è main.cpp)

-> main.cpp -> #include "SDL.h"


Print stringhe
------------------------------------------------------------------------------
https://gigi.nullneuron.net/gigilabs/displaying-text-in-sdl2-with-sdl_ttf/
https://www.libsdl.org/projects/SDL_ttf/
------------------------------------------------------------------------------
Proprietà Progetto
-> Configuration settings
	-> C/C++
		-> General
		-> Additional include directory
		=> SDL2_ttf-2.0.15/include

	-> Linker
		-> General
			-> Additional library directories
			=> SDL2_ttf-2.0.15/lib/x64
		-> Input
			-> Additional dependencies
			=> SDL2_ttf.lib

-> Copiare il font Arial dalla cartella C:\Windows\Fonts\Arial nella root folder del progetto
-> Copiare dalla cartella SDL2_ttf-2.0.15/lib/x64 le 3 dll
	- libfreetype-6.dll
	- SDL2_ttf.dll
	- zlib1.dll
	nella root folder del codice sorgente