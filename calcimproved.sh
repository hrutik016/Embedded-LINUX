echo "Enter X: "
read X
echo "Enter Y: "
read Y
echo "Press any key from +,-,*,/:"
read C
case $C in 
	+)
		echo `expr $X + $Y`
		;;
	-)
		echo `expr $X - $Y`
		;;
	\*)
		echo `expr $X \* $Y`
		;;
	\/)	
		echo `expr $X \/ $Y`
		;;
	*)
esac
	
