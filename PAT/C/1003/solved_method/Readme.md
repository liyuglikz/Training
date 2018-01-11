只有aPbTc情况最复杂
假设a b c的长度分别为A B C
则对A B C递归

bool judge( int A, int B, int C)
{
	if( A == C && B == 1)
		return true;
	else if( A > C || B < 1)
		return false;
	return judge(A, B - 1, C - A);
}
