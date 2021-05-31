# in this code we will be printing every character from 2nd position to the 7th position

while read sentence;
do
echo $sentence | cut -c2-7
done
