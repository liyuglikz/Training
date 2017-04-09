./datamaker > data
#echo "Main"
./Main < data > out1
#echo "Ans"
./Ans < data > out2

#echo "Sort1"
sort -n ./out1 > out11
#echo "Sort1"
sort -n ./out2 > out22
diff out11 out22
