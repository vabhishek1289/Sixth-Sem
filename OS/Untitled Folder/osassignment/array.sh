array_name = ( "value1" "valuen" )
echo "First Index: ${array_name[0]}"
Linux=("${array_name[@]}")
echo "First Index: ${Linux[1]}"
