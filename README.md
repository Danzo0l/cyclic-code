# Infocom
This program provides an analysis of a coder and decoder based on cyclic codes. Cyclic codes are a type of linear block code that are particularly useful in error correction and detection. The program allows you to encode, decode, or perform alternative decoding on a given set of numbers using a specified parameter g and a selected mode.

### Get started

#### Build
- With cmake:
```sh
mkdir build
cd build
cmake ..
```
- With g++:
```sh
mkdir build
g++ ./src/*.cpp -o ./build/cyclic_mode
```
#### Run
- Run code
```
./build/out <mode> -i <input file> -g <generate polynom> -o <output file>
```
#### Program arguments
- `-d` Decoding mode. 
- `-c` Coding mode.
- `-a` Alternative decoding mode.
- `-i <input_file>` Path to the file containing vectors to process.  
  Format imput file:
  ```
  <m>
  16
  7
  ...
  ```
- `-g <g>` Value of the parameter g.
- `-o <output_path>` Path to the file to write the result.  
  Format imput file:
  ```
  <m>;<E>
  31;0
  13;1
  ...
  ```

#### Examples
```
./build/cyclic_mode -d -i input.txt -g 10 -o output.txt
```
