#!/bin/bash
# File: make.sh
# Date: Mon Jul 08 21:34:09 2013 +0800
# Author: Yuxin Wu <ppwwyyxxc@gmail.com>
rm -rf output *.pdf
for i in `find -maxdepth 1 -type d -not -path './.*'`; do
	echo $i
	make -C $i final
	cp $i/output/*.pdf ./
done
mkdir -p output
mv *.pdf output
~/bin/makefile_clean

