# How To Use

Simply add both files to your project 
*(Debugger.h & Debugger.cpp)*

If you want to call the functions just add ``#include <Debugger.h>`` to the top of the file that is going to call it.

*(Your file paths will vary, you might have to do ``#include "Debugger.h"`` or ``#include "./Debugger/Debugger.h"`` and/or etc to correctly path to it)*

This is designed for DLLs, and as of right now I have only made DLLs in C++, I literally have not made anything else. 
The template will demonstrate a fully working and ready-to-compile DLL that when injected will execute the creation of the debug log, which you will find located within the binaries path of your game.

[Download](https://github.com/Aeyth8/T-Debug-Log/archive/refs/heads/main.zip)
