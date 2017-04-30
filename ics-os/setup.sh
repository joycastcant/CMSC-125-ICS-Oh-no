#!/bin/sh

make clean
sudo make install
make
qemu-system-x86_64 -fda ics-os-floppy.img