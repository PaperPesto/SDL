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

-> Target Build x64