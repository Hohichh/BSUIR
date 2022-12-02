#!/bin/bash
if [ -d $1 ] 
then
echo "Результат поиска смотри в result.txt"
find $1 -type f -user $2 -newermt $3 -printf '%f\n' > result.txt
else
echo "Данной папки ($mydir) нет."
fi

