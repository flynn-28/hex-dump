# Hex Dump
Dump a files hex data

## Run
to run, compile the project into binary files for your system or download precompiled binaries [here](https://github.com/flynn-28/hex-dump/releases/tag/release)

## Usage
Usage: ./dump <filename>

## Build

### Windows
1. Create a new project in Visual Studio
2. Use the Windows Desktop Application Template
3. Copy and paste the contents of [main.cpp](https://github.com/flynn-28/hex-dump/blob/main/main.cpp) into the main c++ file
4. Build the project with the keyboard shortcut CTRL + SHIFT + B
5. Navigate to the x64 folder in your project root directory
6. enter the "debug" folder
7. run the program with `hex-dump.exe <filename>`

### Linux and MacOS
1. install g++ compiler: `sudo apt install g++`
2. clone this repository: `git clone https://github.com/flynn-28/hex-dump.git`
3. enter the directory: `cd hex-dump`
4. run build command: `g++ -std=c++11 main.cpp -o hexdump`
5. run the program with: `./hexdump <filename>`
