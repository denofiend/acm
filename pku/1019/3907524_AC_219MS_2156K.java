//
import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		int N,n;
		int i;
		N=cin.nextInt();
		while((N--)>0)
		{
			n=cin.nextInt();
			System.out.println(Get(n));
		}

	}

	static int Get(int n)//获取主串的第n个数字
	{
		int i=1,N;
		for(i=1;;i++)
		{
			N=GetLen(i);
			if(n>N) n-=N;
			else break;
		}
		return getN(n);
	}

	static int GetLen(int n)//获取以n为长度的子串的长(OK)
	{
		int i,T,temp,len;
		temp = n;
		T = nLen(n);
		for(i = 1,len = 0; i < T; i++)
		{
			len += 9 * pow10(i - 1) * i;
		}
		len += T * (n-pow10(T-1) + 1);
		return len;
	}
	static int pow10(int n)//10的N次方(OK)
	{
		int i, result;
		for(i = 0,result = 1;i < n; i++)
		{
			result*=10;
		}
		return result;
	}
	static int getN(int n)//获取子串的第N个数字
	{
		int i;
		for(i=1;;i++)
		{
			if(n<=nLen(i)) break;
			n-=nLen(i);
		}
		return i/pow10(nLen(i)-n)%10;
	}
	static int nLen(int n)//计算一个数字的位数(OK)
	{
		int i;
		for(i=0;n!=0;i++)
		{
			n/=10;
		}
		return i;
	}
}
