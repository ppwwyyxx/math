#!/bin/sh
Time=`date +%m%d%H`
Name=`pwd |sed 's/^.*\///g'`
cd ..
7z a backup/backup_$Name$Time.7z ./$Name
