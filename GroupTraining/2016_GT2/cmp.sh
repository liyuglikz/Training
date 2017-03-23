#!/bin/bash
rm data
rm out1
rm out2

./datamaker > data
cat data | ./Main > out1
cat data | ./Ans > out2

diff out1 out2;
