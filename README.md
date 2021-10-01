# Code-Generator
### Environmental Setup
```
sudo apt install gcc flex bison python3 git
sudo apt install default-jre
```
### Make 
```
make clean && make
./mycompiler < input/in01_arithmetic.c
java -jar jasmin.jar hw3.j
java Main
```
### Judge Score
```
python3 judge/judge.py
```
