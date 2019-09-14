package org.tan.jsoup.utils;
import java.util.regex.Matcher; 
import java.util.regex.Pattern; 

/***
 *  html标签处理工具类 
 *  @author 1
 */
public class HTMLUtil { 
	public static String delHTMLTag(String htmlStr){ 
		//定义 script的正则表达式 
		String regEx_script="<script[^>]*?>[\\s\\S]*?<\\/script>"; 
		//定义 style的正则表达式 
		String regEx_style="<style[^>]*?>[\\s\\S]*?<\\/style>"; 
		//定义HTML标签的正则表达式 
		String regEx_html="<[^>]+>"; 
		Pattern p_script=Pattern.compile(regEx_script,Pattern.CASE_INSENSITIVE); 
		//过滤script标签 
		Matcher m_script=p_script.matcher(htmlStr); htmlStr=m_script.replaceAll(""); 
		Pattern p_style=Pattern.compile(regEx_style,Pattern.CASE_INSENSITIVE); 
		Matcher m_style=p_style.matcher(htmlStr); 
		//过滤style标签 
		htmlStr=m_style.replaceAll(""); 
		Pattern p_html=Pattern.compile(regEx_html,Pattern.CASE_INSENSITIVE); 
		//过滤html标签 
		Matcher m_html=p_html.matcher(htmlStr); htmlStr=m_html.replaceAll(""); 
		//返回文本字符串
		return htmlStr.trim();  
	}
}
