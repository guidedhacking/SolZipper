# SolZipper - Visual Studio Solution Archiver


## What does this do?

Adds Right Click Context Menu to Windows that enables you to right click on a Visual Studio project folder and zip it up in one button click without any unnecessary VS bloat files.

## Why?

Posting Visual Studio projects on forums in zips makes helping people 100% faster/easier than them pasting their code into the post.  But VS projects have lots of bloat and newbies don't understand what files we need so forums get bloated with this 100mb worthless attachments.

Obviously git is OP but newbies don't know how to use git yet.

I haven't coded anything a while, I wanted to do something with std::filesystem so here it is.

## Usage

Run the exe, you have 3 basic options:
1. Install it, including the context menu handler
2. Uninstall it
3. Zip the folder

You can use the right click menu or you can drag and drop your solution folder onto the .exe

## How does it work?
It uses a blacklist of bad folder names and extensions like .gitignore.  It copies the good files to a temp folder.  Then it uses Powershell to zip the folder.

## TODO
Replace powershell with actual zipping lib
Remove ghetto exclusion filter method
Fix exclusion false positives

## Development History
Developed version 1.0