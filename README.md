# SDL2 Game Development Projects

A collection of C++ game development projects built with [SDL2](https://www.libsdl.org/), ranging from basic game loops to a full entity-component-system (ECS) game engine.

## Projects

| Project | Description |
|---|---|
| **GameLoop** | Basic SDL2 game loop setup with event handling, update, and render cycle |
| **GameLoopGUI** | Game loop with a graphical window |
| **DrawingTextures** | Loading and rendering textures using SDL2_image |
| **PrintString** | Rendering text with SDL2_ttf |
| **GameEngine** | Full ECS-based 2D game engine with tile maps, sprites, collision, and keyboard input |
| **GravityGame** | Simple physics/gravity game demo |
| **SoftEngine** | Software renderer with animation, camera, collision, and tile-based maps |

## Requirements

- [Visual Studio](https://visualstudio.microsoft.com/) (projects use `.vcxproj` files, targeting x64)
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/) (for texture projects)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/) (for text rendering projects)

The required SDL2 libraries are included under the `SDL2/`, `SDL2_image-2.0.1/`, and `SDL2_ttf-2.0.15/` directories.

## Setup (Visual Studio)

1. Open the `.sln` file for the project you want to run.
2. Set the build target to **x64**.
3. Ensure the project properties include:
   - **C/C++ → Additional Include Directories**: `SDL2/include`
   - **Linker → Additional Library Directories**: `SDL2/lib/x64`
   - **Linker → Additional Dependencies**: `SDL2.lib`, `SDL2main.lib`
   - **Linker → System → SubSystem**: `Console (/SUBSYSTEM:CONSOLE)`
4. Copy `SDL2/lib/x64/SDL2.dll` into the project's root folder (alongside `main.cpp`).
5. For texture support, add the SDL2_image include/lib paths and copy the required DLLs (`SDL2_image.dll`, `libpng16-16.dll`, `zlib1.dll`) to the project root.

## Structure

```
SDL/
├── SDL2/                    # SDL2 library
├── SDL2_image-2.0.1/        # SDL2_image library
├── SDL2_ttf-2.0.15/         # SDL2_ttf library
├── GameLoop/                # Basic game loop
├── GameLoopGUI/             # Game loop with GUI
├── DrawingTextures/         # Texture rendering
├── PrintString/             # Text rendering
├── GameEngine/              # ECS game engine
├── GravityGame/             # Gravity/physics demo
└── SoftEngine/              # Software renderer
```
