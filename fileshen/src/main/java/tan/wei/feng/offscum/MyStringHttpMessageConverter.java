package tan.wei.feng.offscum;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

import org.springframework.http.converter.StringHttpMessageConverter;

public class MyStringHttpMessageConverter extends StringHttpMessageConverter{
	
	public static final Charset DEFAULT_CHARSET = StandardCharsets.UTF_8;
	
	public MyStringHttpMessageConverter() {
		this(DEFAULT_CHARSET);
	}

	public MyStringHttpMessageConverter(Charset defaultCharset) {
		super(defaultCharset);
	}

}
