echo "Enter A:"
read A
echo "Enter B:"
read B
echo "Enter C:"
read C

read xyz

cat > $A $B $C > $xyz

echo xyz

echo "No. of words:"

wc -w $xyz
