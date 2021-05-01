file=""

echo "Enter filename"
read file

if [ ! -f $file ]
then
	echo "$file not a file"
	exit 1
fi

sort -n $file
