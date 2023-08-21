# PaperPixel

This is PaperPixel. A game engine written in C++.

## How to use PaperPixel

The PaperPixel game engine is a shared library. To use PaperPixel:

1. Add the include file to your project's include directories.
2. Link against the projects static library.
3. Add the shared library to your project's output directory.

To use the code simply add the preprocessor directive
`#include <PaperPixel/PaperPixel.h>` and create a class that overrides
the `pp::Application` class's virtual functions, which are:

* `void OnCreate()`
* `void OnUpdate(float delta)`
* `void OnRender(pp::Renderer renderer)`

Then in your main function write the following

```c++
int main()
{
    // Assuming the Game clazs extends the pp::Application
    Game game;
    if (game.IsCreated())
        game.Run();

    return 0;
}
```
