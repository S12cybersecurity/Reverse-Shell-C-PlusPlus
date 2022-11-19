# C++ Reverse-Shell
Simple C++ Reverse Shell

From https://cocomelonc.github.io/tutorial/2021/09/15/simple-rev-c-1.html

Little bit modified by my.

**Compile**

i686-w64-mingw32-g++ reverse-shell.cpp -o revshell.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -fpermissive >/dev/null 2>&1

