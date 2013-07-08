#!/bin/bash
# File: make.sh
# Date: Mon Jul 08 16:48:10 2013 +0800
# Author: Yuxin Wu <ppwwyyxxc@gmail.com>
rm -rf output *.pdf
for i in `find -maxdepth 1 -type d -not -path './.*'`; do
	echo $i
	make -C $i
	cp $i/output/*.pdf ./
done
mkdir -p output
mv *.pdf output
~/bin/makefile_clean

