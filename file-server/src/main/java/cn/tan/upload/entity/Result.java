package cn.tan.upload.entity;

/**
 * 返回的数据格式
 * @author 10159
 *
 */
public class Result {
	
	// 返回码
	private Integer code;
	// 返回信息
	private String message;
	// 返回数据
	private Object data;
	
	public Integer getCode() {
		return code;
	}

	public void setCode(Integer code) {
		this.code = code;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Object getData() {
		return data;
	}

	public void setData(Object data) {
		this.data = data;
	}

	public Result() {
		super();
	}

	public Result(Integer code, String message) {
		super();
		this.code = code;
		this.message = message;
	}


	public Result(String message) {
		super();
		this.message = message;
	}

	public Result(Integer code, String message, Object data) {
		super();
		this.code = code;
		this.message = message;
		this.data = data;
	}

	public Result(Integer code) {
		super();
		this.code = code;
	}
	
	
	
	
}
