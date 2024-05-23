read -p "Enter Consumer Numeber: " num
read -p "Enter Consumer Name: " name
read -p "Enter Previous Units: " units_prev
read -p "Enter Present Units: " units_pres



units=$(( -$units_prev + $units_pres))
bill=0

if [ $units -le 50 ]
then
	bill=2

elif [ 51 -le $units ] &&[ $units -le 100 ]
then
	bill=2.25

elif [ 101 -le $units ] && [ $units -le 200 ]
then
        bill=2.5

elif [ 201 -le $units ] && [ $units -le 400 ]
then
        bill=3

elif [ 400 -le $units ] && [ $units -le 600 ]
then
        bill=3.5

else
	bill=4

fi


if [ $(echo "$bill * 10 > 5000" | bc -l) ]
then
	bill=$(echo "scale=2; $bill - ($bill/10)" | bc)
fi

echo "Total Units = $units"
echo "Total Bill = $bill"

