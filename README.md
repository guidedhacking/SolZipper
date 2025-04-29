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

<h3>Official GH Courses</h3>
<ul>
	<li><a href="https://guidedhacking.com/ghb" target="_blank">The Game Hacking Bible</a>&nbsp;- a massive 70 chapter Game Hacking Course</li>
	<li><a href="https://guidedhacking.com/threads/squally-cs420-game-hacking-course.14191/" target="_blank">Computer Science 420</a>&nbsp;- an eight chapter lecture on CS, Data Types &amp; Assembly</li>
	<li><a href="https://guidedhacking.com/forums/binary-exploit-development-course.551/" target="_blank">Binary Exploit Development</a>&nbsp;- a 9 chapter series on exploit dev&nbsp;from a certified OSED</li>
	<li><a href="https://guidedhacking.com/forums/game-hacking-shenanigans/" target="_blank">Game Hacking Shenanigans</a>&nbsp;- a twenty lesson Cheat Engine hacking course</li>
	<li><a href="https://guidedhacking.com/threads/python-game-hacking-tutorial-1-1-introduction.18695/" target="_blank">Python Game Hacking Course</a>&nbsp;- 7 chapter external &amp; internal python hack lesson</li>
	<li><a href="https://guidedhacking.com/threads/python-game-hacking-tutorial-2-1-introduction.19199/" target="_blank">Python App Reverse Engineering</a>&nbsp;- Learn to reverse python apps in 5 lessons</li>
	<li><a href="https://guidedhacking.com/threads/web-browser-game-hacking-intro-part-1.17726/" target="_blank">Web Browser Game Hacking</a>&nbsp;- Hack javascript games with this 4 chapter course</li>
	<li><a href="https://guidedhacking.com/forums/roblox-exploit-scripting-course-res100.521/" target="_blank">Roblox Exploiting Course</a>&nbsp;- 7 Premium Lessons on Hacking Roblox</li>
	<li><a href="https://guidedhacking.com/forums/java-reverse-engineering-course-jre100.538/" target="_blank">Java Reverse Engineering Course</a>&nbsp;- 5 chapter beginner guide</li>
	<li><a href="https://guidedhacking.com/forums/java-game-hacking-course-jgh100.553/" target="_blank">Java Game Hacking Course</a>&nbsp;- 6 Chapter Beginner Guide</li>
</ul>

GuidedHacking® - The Game Hacking Bible® - © 2025 Guided Hacking LLC. All Rights Reserved.
