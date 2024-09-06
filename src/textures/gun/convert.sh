
read input

while [ $input -ge 0 ]
do
	convert *$input*.png pistol_$input.xpm
	input=$(( input -1 ))
done