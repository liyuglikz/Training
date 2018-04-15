比较复制构造函数与重载等于号的不同

class Student
{
	public:
		
		/* 复制构造函数调用情况：
					对象实例化，以另一个对象赋值时: Student a(b), c = d;
					函数参数传值调用
					函数返回值*/
			
		Student( const Student &k);
		
		/* 重载运算符 '='
			a = b;赋值时
		*/
		Student operator = (const Student &k);
};
