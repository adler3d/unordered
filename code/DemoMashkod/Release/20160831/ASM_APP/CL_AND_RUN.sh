set -e
./V2.exe HIDE
mv qapcppout.asm asm2mashkod2016.h
./Asm2Mashkod.exe HIDE
mv mashkod.asm mashkod.txt
./ASM_APP.exe