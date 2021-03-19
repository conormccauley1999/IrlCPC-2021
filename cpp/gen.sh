for VAR in "a" "b" "c" "d" "e" "f" "g" "h" "i" "j" "k" "l" "m" "n" "o" "p"
do
  echo $VAR
  mkdir $VAR
  cp template.cpp $VAR/$VAR.cpp
  cd $VAR
  touch in1
  touch in2
  touch in3
  touch in4
  cd ..
done  