#in this program we are printing every character from first position to the 4th position

while read line
do
echo $line | cut -c1-4
done
