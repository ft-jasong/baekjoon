#!/bin/bash

# Define the output files
mine_output_file="mineout.txt"
answer_output_file="answerout.txt"
diff_argument_file="diff_argument2.txt"

# Loop through the input arguments
for (( r1=-10; r1<=10; r1++ )); do
  for (( c1=-10; c1<=10; c1++ )); do
    for (( r2=r1; r2<=r1+49 && r2<=10; r2++ )); do
      for (( c2=c1; c2<=c1+4 && c2<=10; c2++ )); do
        # Output the current arguments
        echo "Running with arguments: r1=$r1, c1=$c1, r2=$r2, c2=$c2"

        # Run the executable files and save the output to files
        ./mine $r1 $c1 $r2 $c2 > "$mine_output_file"
        ./answer $r1 $c1 $r2 $c2 > "$answer_output_file"

        # Compare the output values and append arguments to the diff_argument_file if they are different
        if diff "$mine_output_file" "$answer_output_file" > /dev/null; then
          echo "Outputs are the same"
        else
          echo "Outputs are different for arguments: r1=$r1, c1=$c1, r2=$r2, c2=$c2" >> "$diff_argument_file"
        fi
      done
    done
  done
done
