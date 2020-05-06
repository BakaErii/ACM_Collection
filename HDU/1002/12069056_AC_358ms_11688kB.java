/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 19:21:43
 *
 */

import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		String stra,strb;
		int i, n;
		n = in.nextInt();
		for (i = 0; i < n; i++) {
			stra = in.next();
			strb = in.next();
			BigInteger biga = new BigInteger(stra);
			BigInteger bigb = new BigInteger(strb);
			if (i != 0){
				System.out.println();
			}
			System.out.println("Case " + (i + 1) + ":");
			System.out.println(biga + " + " + bigb + " = " + biga.add(bigb) );
		}
	}
}