/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 18:16:49
 *
 */

import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int a, b;
		while (in.hasNextInt()) {
			a = in.nextInt();
			b = in.nextInt();
			if (a == 0 && b == 0)
				return;
			else
				System.out.println(a + b);
		}
	}
}