This is a fork of Michael Aaron Safyan's cpp-project-template,
available at: https://code.google.com/p/cpp-project-template/.

 1. Prerequisites
 2. Building
 3. Installing
 4. Contributing

## 1. PREREQUISITES

 This project requires:
  * Cross-platform Make (CMake) v2.8.9+
  * GNU Make or equivalent.
  * GCC or an alternative, reasonably conformant C++ compiler.
  * Qt Framework v4.7+

## 2. BUILDING

 This project uses the Cross-platform Make (CMake) build
 system. However, we have conveniently provided a wrapper configure
 script and Makefile so that the typical build invocation of
 "./configure" followed by "make" will work.  For a list of all
 possible build targets, use the command "make help".

 NOTE: Users of CMake may believe that the top-level Makefile has been
 generated by CMake; it hasn't, so please do not delete that file.

## 3. INSTALLING

 Once the project has been built (see "BUILDING"), execute "sudo make
 install".

## 4. CONTRIBUTING

 This project makes an earnest attempt to follow the Google C++ Style
 Guide, available at:
 http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml. Please
 follow the coding style. In some cases (commonly when subclassing
 external files) the files may follow a different coding style as
 defined by the project. In such cases, follow the style of the file
 to maintain consistency.