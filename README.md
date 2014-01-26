BAPS Readme - Broadcasting and Presenting Suite for URY
=======================================================

Current Version: 0.0.1
----------------------

### Contents
1. About BAPS
2. Reporting bugs and Contributing
3. Building BAPS
4. License
5. Credits



1 About BAPS
------------

BAPS is a collection of programs, utilities, websites, and schemas that assist
URY with day to day broadcasting and presenting activities. BAPS is highly
modular and distict parts of the suite can be run independently. The full suite
does however interoperate seemlessly to provide a fully featured broadcast
platform.

This is the playout system, which manages playlists and the output of sound.



2 Reporting bugs and contributing
---------------------------------

If you spot any bugs or glitches in BAPS, please report it to our bug tracker:

http://www.ury.org.uk/support

Please make sure that you're using the latest available version before reporting
a bug. You can check the issue tracker to see if the bug you've found is already
reported (or fixed!).

If you have made improvements yourself to the source code, please also share
that with us via github, irc or email.



3 Building BAPS
---------------

Prerequisites to building BAPS:
- gcc/clang (4.8+/3.3+ respectively, for C++11)
- CMake (2.8)
- git
- doxygen (optional)

Libaries:
- Qt5

The use of git is strongly encouraged as only that allows to keep track of
changes.

Once all tools are installed, get a checkout of the repository and you can build
BAPS using cmake. Once that is done, the following make targets are available:

| Target       | Description                                     |
| ------------ | ----------------------------------------------- |
| **help**     | displays a list of make targets.                |
| **clean**    | cleans build files (not CMake files)            |
| **doc**      | build the documentation (requires doxygen)      |
| **run**      | run BAPS immediately after building             |
| **gdbrun**   | run BAPS immediately after building, inside gdb |

Given the usual case that you modify something within BAPS and want to test
that, a simple 'make' should suffice and you can immediately test the changes.



3 License
---------

BAPS is licenced under MIT License. See LICENSE.txt for more details.



5 Credits
---------

BAPS is credited as being created by the following people
(in reverse alphabetical order):

* Lord Aro (Charles Pigott)
* liamfraser (Liam Fraser)
* CaptainHayashi (Matt Windsor)

and of course,
* Matthew Fortune


Contact: on irc://irc.freenode.net/#ury

