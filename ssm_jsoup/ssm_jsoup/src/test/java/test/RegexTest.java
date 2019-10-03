package test;

import org.junit.Test;

public class RegexTest {
	
	@Test
	public void regexTest() {
		String url = "https://blog.csdn.net/weixin_43606158/article/details/91164392";
		
//		String descr = Pattern.compile("([a-z]+)(t/)*(/ar)").matcher(url).replaceAll("");
//		System.out.println(descr);
		int tt = url.indexOf("net/");
		int ts = url.indexOf("/art");
		String result = url.substring(tt,ts).replace("net/", "");
		System.out.println(tt);
		System.out.println(ts);
		System.out.println(result);
	}
	
}
