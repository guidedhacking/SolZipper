# SolZipper - Visual Studio Solution Archiver
Version 1.0

## What does this do?

-   Quickly zips up VS projects without the unnecessary bloat files
-   Adds Right Click Context Menu to Folders to Zip up Projects
-   You can also Drag & Drop your VS project onto the .exe

## Video Demo
[![SolZipper Demo Video](http://img.youtube.com/vi/LDdOMEZz4Ik/0.jpg)](https://youtu.be/LDdOMEZz4Ik "SolZipper Demo")

## Why?

Posting Visual Studio projects on forums in zips makes helping people 100% faster/easier than them pasting their code into the post.

VS projects have lots of bloat and newbies don't understand what files we need so forums get bloated with worthless 100mb attachments.

I wanted to do something with std::filesystem and encourage people to post entire projects that are easy to debug.

## Usage

Run the exe, you have 3 basic options:
1.   Install it, including the context menu handler
2.   Uninstall it
3.   Zip the folder

You can use the right click menu or you can drag and drop your solution folder onto the .exe

## How does it work?
It uses a blacklist of bad folder names and extensions similar to .gitignore.  It copies the good files to a temp folder.  Then it uses Powershell to zip the folder.

## Requirements
-   Visual C++ Redistributables
-   Powershell

More info & release build @ https://guidedhacking.com/resources/solzipper-easily-zip-visual-studio-projects-for-uploading.21/

## TODO
*   Replace powershell with actual zipping lib
*   Remove ghetto exclusion filter method
*   Fix exclusion false positives

## Development History
Developed version 1.0
Developed version 1.1 support GB2312 path string
