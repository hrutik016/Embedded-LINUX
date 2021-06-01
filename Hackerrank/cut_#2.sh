# in this program we are finding the characters present on the 2nd and 7th position of the word

while read line
do
echo $line | cut -c 2,7
done
