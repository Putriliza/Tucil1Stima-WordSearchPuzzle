# WORD SEARCH PUZZLE SOLVER USING BRUTE FORCE ALGORITHM
## TUGAS KECIL 1 IF2211 STRATEGI ALGORITMA


### GENERAL INFORMATION
This is a simple program to solve word search puzzle using brute force algorithm built with C++. The input received via text file (.txt) consists of a matrix of puzzles, followed by one blank line, and a list of keywords that you want to search. The words in the puzzle can be
found in eight possible directions, vertical up, vertical down, horizontal to the right, horizontally to the left, diagonally to the top right, diagonally to the bottom right, diagonally to the left
up, and diagonally to the bottom left.

### Important Files
| Location          |  Content                  |
|-------------------|---------------------------|
| `/doc`            | Laporan                   |
| `/src`            | Source Code               |
| `/bin`            | Executable                |
| `/test`           | Text files as inputs      |

### REQUIREMENT
It is recommended to run this program within Windows. GCC compiler is required to be installed on your device if you want to re-compile. You can get it from `https://www.mingw-w64.org/` and then use your favorite text editor. There are no additional requirements to run this program.
### HOW TO RUN
* First, clone this repository
   ```
   git clone https://github.com/Putriliza Tucil1Stima-WordSearchPuzzle.git
   ```
* Change current working directory to /bin. If you are in the root directory, on the terminal
   ```
   cd bin
   ```
* Then run
   ```
   ./main
   ```
* Or simply, just go to the file explorer then click the `main.exe`

* If you want to develop and recompile this program, change directory to /src then
  ```
  g++ main.cpp search.cpp puzzle.cpp words.cpp fileToData.cpp -o ../bin/main.exe
  ```



### AUTHOR
This program was made by [Putri Nurhaliza - 13520066](mailto:putrilza05@gmail.com)

