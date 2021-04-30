echo "Enter the first no: "
read a
echo "Enter the second no: "
read b
echo "Enter the third no: "
read c

if [ $a -gt $b ]
then 
	if [ $a -gt $c ]
	then 	
		echo $a "is larger"
	else
		echo $c "is larger"
	fi
else
	if [ $b -gt $c ]
	then 
		echo $b "is larger"
	else
		echo $c "is larger"
	fi
fi
  
