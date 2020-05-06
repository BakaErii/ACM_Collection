/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 18:30:38
 *
 */

import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int n, i, sum;
		while (in.hasNextInt()) {
			n = in.nextInt();
			sum = 0;
			for (i = 0; i < n; i++)
				sum += in.nextInt();
			System.out.println(sum);
		}
	}
}