import java.io.*;
import java.lang.*;
import java.util.*;

public class CountingSorting
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		ArrayList<Integer> ai = new ArrayList<Integer>();
		for(int iter = 0; iter < n; iter++)
		{
			ai.add(input.nextInt());
		}
		// main program starts from here...
		int mx = 0;
		for(int iter = 0; iter < ai.size(); iter++)
		{
			mx = Math.max(mx, ai.get(iter));
		}
		int[] dp = new int[mx+1];
		for(int iter = 0; iter <= mx; iter++)
		{
			dp[iter] = 0;
		}
		for(int iter = 0; iter < ai.size(); iter++)
		{
			dp[ai.get(iter)]++;
		}

		for(int iter = 0; iter <= mx; iter++)
		{
			int temp = dp[iter];
			while(temp-- > 0)
			{
				System.out.print(iter + " ");
			}
		}
		System.out.println();
	}
}
import java.io.*;
import java.lang.*;
import java.util.*;

public class CountingSorting
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		ArrayList<Integer> ai = new ArrayList<Integer>();
		for(int iter = 0; iter < n; iter++)
		{
			ai.add(input.nextInt());
		}
		// main program starts from here...
		int mx = 0;
		for(int iter = 0; iter < ai.size(); iter++)
		{
			mx = Math.max(mx, ai.get(iter));
		}
		int[] dp = new int[mx+1];
		for(int iter = 0; iter <= mx; iter++)
		{
			dp[iter] = 0;
		}
		for(int iter = 0; iter < ai.size(); iter++)
		{
			dp[ai.get(iter)]++;
		}

		for(int iter = 0; iter <= mx; iter++)
		{
			int temp = dp[iter];
			while(temp-- > 0)
			{
				System.out.print(iter + " ");
			}
		}
		System.out.println();
	}
}
