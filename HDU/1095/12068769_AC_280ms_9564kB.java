/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 18:33:25
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
			System.out.println(a + b);
			System.out.println();
		}
	}
}