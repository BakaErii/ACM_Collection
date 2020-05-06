/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-11-24 14:19:52
 *
 */

import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		BigInteger a, b;
		while (in.hasNext() == true) {
			a = in.nextBigInteger();
			b = in.nextBigInteger();
			System.out.println(a.mod(b));
		}
	}
}