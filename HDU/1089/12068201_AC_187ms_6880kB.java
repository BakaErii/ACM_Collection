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
	public static void main(String args[])
		throws IOException {
		int a, b, ans;
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		while (in.nextToken() != StreamTokenizer.TT_EOF){
			a = (int) in.nval;
			in.nextToken();
			b = (int) in.nval;
			out.println(a + b);
		}
		out.flush();
	}
}