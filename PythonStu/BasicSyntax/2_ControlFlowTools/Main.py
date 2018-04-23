#!/usr/bin/python3

# sorting:

s = [3, 1, 5, 1, 4, 9, 2, 6];
k = 0; #tmp variable

# loop:
for i in range( len(s) - 1):
	for j in range( len(s) - 1 - i):
		if s[j] > s[j + 1]:
			k = s[j];
			s[j] = s[j + 1];
			s[j + 1] = k;


for i in range( len(s) ):
	print( s[i] );

	if s[i] < 0:
		break;
	elif s[i] == 0:
		continue;
	else:
		continue;
