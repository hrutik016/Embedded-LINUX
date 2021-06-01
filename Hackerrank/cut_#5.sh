# output will contain N lines, for each line in the input and prints the first three fields.

while read line
do
    echo -e "$line" | cut -f -3 
done
