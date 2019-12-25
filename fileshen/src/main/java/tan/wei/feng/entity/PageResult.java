package tan.wei.feng.entity;

import java.util.List;

import lombok.Data;

/**
 * 分页结果类
 * @author 1
 * @param <T>
 *
 */
public @Data class PageResult<T> {
	
	
	private Long total;
	private List<T> rows;
	private String message;
	
	public PageResult(Long total, List<T> rows) {
		super();
		this.total = total;
		this.rows = rows;
	}

	public PageResult(String message) {
		super();
		this.message = message;
	}
	
	
	
	
	
	
	
}
