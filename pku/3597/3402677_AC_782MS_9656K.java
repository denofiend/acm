import java.io.*;
import java.util.*;
import java.lang.Math;
import java.math.BigInteger;

public class Main
{
	public static void main(String args[]) throws Exception
	{
        BigInteger []ans = new BigInteger[5001];
        init(ans);
		Scanner cin = new Scanner(System.in);
		int n;
		BigInteger mod = BigInteger.valueOf((long)2);
		mod = mod.pow(64);
		while (cin.hasNext())
		{
            n = cin.nextInt();
            System.out.println(ans[n - 2].mod(mod));
		}
	}
	static void init(BigInteger ans[])
	{
        ans[1] = BigInteger.valueOf((long)1);
        ans[2] = BigInteger.valueOf((long)3);

        for (int n = 3; n < 5001; n ++)
        {
            BigInteger an_1 = BigInteger.valueOf((long)(11 * n * (2 * n - 1)));
            BigInteger an = BigInteger.valueOf((long)(5 * n * (n + 1)));
            BigInteger an_2 = BigInteger.valueOf((long)(3 * (3 * n - 2) * (3 * n - 4)));

            ans[n] = (an_1.multiply(ans[n - 1]).add(an_2.multiply(ans[n - 2]))).divide(an);
        }
	}
}
