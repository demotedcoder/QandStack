## Compile and Run(Linux)

```path
If you don't have installed Visual Studio, go to ./Algorithms dir, and there you can find the source file.
```
```cpp
sudo apt-get update
sudo apt-get install build-essential manpages-dev
Verify that the compiler is successfully installed: gcc --version
```
```cpp
gcc Source.cpp -o source
./source
```
...
If you get this error: ‘scanf_s’ was not declared in this scope... Just replace scanf_s with scanf.
