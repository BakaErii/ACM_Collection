/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 18:13:41
 *
 */

import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int i, n, a, b;
		n = in.nextInt();
		for (i = 0; i < n; i++) {
			a = in.nextInt();
			b = in.nextInt();
			System.out.println(a + b);
		}
	}
}