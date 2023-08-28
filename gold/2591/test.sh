for ((i = 0; i <= 100000000; i++))
do
    # echo "Running ans with parameter $i"
    ans_output=$(./ans $i)

    # echo "Running mine with parameter $i"
    mine_output=$(./mine $i)

    if [ "$ans_output" != "$mine_output" ]; then
        echo "Outputs are different for parameter $i"
        echo "ans output: $ans_output"
        echo "mine output: $mine_output"
    fi
done