echo "Enter Name:"
read value
if [ $value = '100' ]
then 
	echo "Enter X:"
	read x
	if [ $x = "100" ]
	then
		echo "valid value"
	else
		echo "invalid value"
	fi
else
echo not proper
fi
	
