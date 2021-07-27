# it should return 3rd character of every word

while read line
do
echo $line | cut -c 3
done
