/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 17:22:50
 *
 */

import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		int a, b, ans;
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			a = in.nextInt();
			b = in.nextInt();
			ans = a + b;
			System.out.println(ans);
		}
	}
}