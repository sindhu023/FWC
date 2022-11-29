#!/bin/bash

#/home/student/assembly
#avra xor.asm 
#sudo chmod -R 777 /dev/ttyACM0
#avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -U flash:w:xor.hex:i

 
/home/student/Downloads/asg3/docs
sudo chmod -R 777 /dev/ttyACM0
make clean
make


/home/student/Downloads/asg3/docs
pdflatex xor.tex
xdg-open xor.pdf





