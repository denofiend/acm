
import java.util.*;

import java.math.*;



class Main
{
	static void init(BigInteger Cmn[][]){
		Cmn[0][0] = BigInteger.ONE;
		for (int i = 1; i <= 200; ++i)
		{
			Cmn[i][0] = BigInteger.ONE;
			for (int j = 1; j < i; ++j)
			{
				Cmn[i][j] = Cmn[i-1][j].add(Cmn[i-1][j-1]);
			}
			Cmn[i][i] = BigInteger.ONE;
		}
	}
	public static void main(String[] args)
	{
		int n;
		BigInteger t;
		BigInteger a[] = new BigInteger[300];
		BigInteger b[] = new BigInteger[300];
		BigInteger Cmn[][] = new BigInteger[300][300];
		init(Cmn);
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
	
			b[n] = a[n];
			for (int i = n-1; i >= 0; --i)
			{
				b[i] = a[i];
				BigInteger tmp = BigInteger.ZERO;
				int k = 1;
				int j = i+1;
				for (; j <= n; ++j)
				{
					BigInteger cmn = Cmn[j][k];
					cmn = cmn.multiply( cal1(t, k));
					cmn = cmn.multiply( b[(int)j] );
					tmp = tmp.add(cmn);
					k++;
				}
				
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
