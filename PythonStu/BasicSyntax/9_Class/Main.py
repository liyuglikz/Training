#!/usr/bin/python3

# define:

'''Template:
	class MyClass:
		define __init__(self):
			...
		define func(self)
			return

'''


# define example:
class MyClass:
	__t = 0	# private member
	i = 0
	def __init__(self): #init method
		self.data = []

	def f1(self):	#member method's first argument must be 'self')
		return 'hello'

	def __f2(self):
		return 0
# use example:
x = MyClass();

# method to func
xf1 = x.f1;

print( x.f1() );
print( xf1() );

# inheritance

class BaseClass:
	i = 0;
	def __init__(self):
		i = 0;
	def f1(self):
		return 0;

class DerivedClass( BaseClass ):
	def __init__(self):
		i = 1;
	def f1(self):
		return 2;
	
c1 = BaseClass()
c2 = DerivedClass()

print( c1.i );
print( c2.i );
print( c1.f1() );
print( c2.f1() );
