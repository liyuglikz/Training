(1) if Statments

		>>> x = int(input("Please enter an integer: "))
		Please enter an integer: 42
		>>> if x < 0:
		...     x = 0
		...     print('Negative changed to zero')
		... elif x == 0:
		...     print('Zero')
		... elif x == 1:
		...     print('Single')
		... else:
		...     print('More')
		...
		More

Loop:
	(2) for Statments

			>>> # Measure some strings:
			... words = ['cat', 'window', 'defenestrate']
			>>> for w in words:
			...     print(w, len(w))
			...
			cat 3
			window 6
			defenestrate 12

	(2.2) while:
			while i < n:
				i = i + 1;

(3) the rang() function

		[3.1]
			for i in range(5)
				print(i)

			range(5, 10)
				5, 6, 7, 8, 9

			range(0, 10, 3)
				0, 3, 6, 9

			range( -10, -100, -30)
				-10, -40, -70

		#str:
			>>> a = ['Mary', 'had', 'a', 'little', 'lamb']
			>>> for i in range(len(a)):
			...     print(i, a[i])
			...
			0 Mary
			1 had
			2 a
			3 little
			4 lamb



(4) functions

	# define:
		def func( a, b, c):
			....
			....
			return a + b + c;

	# call:
		result =  func(1, 2, 3)

	# default arguments
		def func( a, b = 100, c = 'hello'):
			...

		#warning: default value only load once

(5) Lambda Expressions
	def make_incrementor(n):
			return lambda x: x + n


(6) docments
	def my_func():
		""" documents...
			....
		"""
		pass

(7) fuction annotations

	>>> def f(ham: str, eggs: str = 'eggs') -> str:
	...     print("Annotations:", f.__annotations__)
	...     print("Arguments:", ham, eggs)
	...     return ham + ' and ' + eggs
	...
	>>> f('spam')
	Annotations: {'ham': <class 'str'>, 'return': <class 'str'>, 'eggs': <class 'str'>}
	Arguments: spam eggs
	'spam and eggs'
