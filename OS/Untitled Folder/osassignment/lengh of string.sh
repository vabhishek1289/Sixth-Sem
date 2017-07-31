echo "Enter string"
read str
length=`echo $str | wc -c`
length=`echo $length -1 |bc`
if [ $length -lt 10 ]
then
	echo "Number enterded is less than 10"
fi

