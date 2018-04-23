#!/usr/bin/python3

###########################
# int:
k_int = 1;

# float:
k_float = 1.0;

# double:
k_double = 1.0;

print( k_int );
print( k_float );
print( k_double );


###########################
# string:
s_str = 'this is a demo'

# get first character
print( s_str[0] );

# get last character
print( s_str[-1] );

# get a sub str [1:3]
print( s_str[1:3] );

# get a pre-str [0:2]
print( s_str[:2] );


###########################
# lists:
squares = [3, 1, 4, 1, 5];

print( squares );
print( squares[0] );

squares += [9, 2, 6]
print( squares );
print( squares[2:5] )
