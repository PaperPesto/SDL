# Per la libreria SDL
-------------------------------------------------------------------------------------------
Configurazione progetto

-> Impostare Target Build x64 (se non si imposta sin da subito e si fa una build a 32 poi impazzisce)

-> Creare main.cpp

Proprietà Progetto
-> Configuration Properties
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




# Per le textures
-------------------------------------------------------------------------------------------
Proprietà progetto
-> Configuration Properties
	-> VC++ Directories
		-> Include Directories
			=> SDL2_image-2.0.1\include
		-> Library Directories
			=> SDL2_image-2.0.1\lib\x64

	-> C/C++
		-> General
			-> Additional Include Directories
				=> SDL2_image-2.0.1\include (sopra SDL2\include, l'ordine conta)

	-> Linker
		-> General
			-> Additional Library Directories
				=> SDL2_image-2.0.1\lib\x64 (sopra SDL2\lib\x64, l'ordine conta)
		-> Input
			-> Additional Dependencies
				=> SDL2_image.lib (per ultima, non so se l'ordine conta)

Aggiungere 3 dll (x64) alla root folder del progetto dalla cartella SDL2_image-2.0.1/lib/x64
- libpng16-16.dll
- SDL2_image.dll
- zlib1.dll