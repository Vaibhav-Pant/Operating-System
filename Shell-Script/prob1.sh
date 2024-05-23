fact(){
        sum=1
        for(( i=2; i<=$1; i++));do
                sum=$((sum * i))
        done
        echo $sum
}

function sins {
	echo -n Enter the value of n:
	read n
	echo -n Enter the value of x in radians:
	read x
	sum=0
	for(( i=0; i<n; i++ )); do

		diff=$(echo "scale=5; (($x ^ (2*$i + 1))/$(fact 2*$i+1))" | bc)
		sum=$(echo "scale=5;  $sum + (($diff * (-1^$i)))" | bc)
	done;

	echo "SIN($x) = $sum"
}



function coss {
	echo -n Enter the value of n:
        read n
        echo -n Enter the value of x in radians:
        read x
        sum=0
        for(( i=0; i<n; i++ )); do

                diff=$(echo "scale=5; (($x ^ (2*$i))/$(fact 2*$i))" | bc)
                sum=$(echo "scale=5;  $sum + (($diff * (-1^$i)))" | bc)
        done;

        echo "COS($x) = $sum"
}


echo 1. Sin series
echo 2. Cos series

echo -n Choose 1/2 :
read x


if [ $x == 1 ]
then
	sins
else
	coss
fi


