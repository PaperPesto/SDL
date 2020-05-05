# Per la libreria SDL
-------------------------------------------------------------------------------------------
Configurazione progetto

-> Impostare Target Build x64 (se non si imposta sin da subito e si fa una build a 32 poi impazzisce)

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
			-> SDL2.lib
			=> SDL2main.lib
		-> System
			-> SubSystem
			=> Console (/SUBSYSTEM:CONSOLE)

-> Copiare SDL2/lib/x64/SDL2.dll nella main root del progetto (dove c'è main.cpp)

-> main.cpp -> #include "SDL.h"




# Per le textures
-------------------------------------------------------------------------------------------
Aggiungere alla root folder la libreria per SDL dalla cartella SDL2/lib/x64
- SDL2.dll

Aggiungere 3 dll (x64) alla root folder del progetto dalla cartella SDL2_image-2.0.1/lib/x64
- libpng16-16.dll
- SDL2_image.dll
- zlib1.dll