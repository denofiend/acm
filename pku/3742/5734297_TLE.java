
import java.util.*;

import java.math.*;



class Main
{
	public static void main(String[] args)
	{
		int n;
		BigInteger t;
		BigInteger a[] = new BigInteger[300];
		BigInteger b[] = new BigInteger[300];
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext())
		{
			n = cin.nextInt();
			t = cin.nextBigInteger();
			t = t.multiply( BigInteger.valueOf((long)-1));
			
			for (int i = 0; i <= n; ++i)
			{
				a[i] = cin.nextBigInteger();
			}
			
			//for (int i = 0; i <= n; ++i)
			//{
			//	System.out.println(a[i]);
			//}
	
			b[n] = a[n];
			for (int i = n-1; i >= 0; --i)
			{
				//System.out.print("i = " + i);
				b[i] = a[i];
				BigInteger tmp = BigInteger.ZERO;
				long k = 1;
				long j = i+1;
				for (; j <= n; ++j)
				{
					BigInteger cmn = cal(j, k);
					cmn = cmn.multiply( cal1(t, k));
					cmn = cmn.multiply( b[(int)j] );
					//System.out.print(" cmn = " + cmn);
					tmp = tmp.add(cmn);
					k++;
				}
				//System.out.println(" tmp = " + tmp);
				b[i] = b[i].subtract(tmp);
			}
			System.out.print(b[0]);
			for (int i = 1; i <= n; ++i)
			{
				System.out.print(" " + b[i]);
			}
			System.out.println();
		}
	}
	static long gcd(long a, long b){
		if (0 == b)	return a;
		else return gcd(b, a % b);
	}
	static BigInteger cal(long m, long n){
		BigInteger ret = BigInteger.ONE;
		for (int i = 0; i < n; ++i)
		{
			long mm = gcd(i+1, m-i);
			
			ret = ret.multiply( BigInteger.valueOf((m-i) / mm));
			ret = ret.divide( BigInteger.valueOf( (i+1) / mm));
		}
		return ret;
	}
	static BigInteger cal1(BigInteger t, long k){
		if (0 == k)	return BigInteger.ONE;
		else
		{
			BigInteger tmp = cal1(t, k / 2);
			tmp = tmp.multiply(tmp);
			if (1 == k % 2) tmp = tmp.multiply( t );
			return tmp;
		}
	}
}
