package tan.wei.feng.model.entity;

import java.io.Serializable;
import java.util.List;

import lombok.Data;

/**
 * 分页结果类
 * @author 1015956962@163.com
 * @param <T>
 *
 */
public @Data class PageResult<T> implements Serializable{
	
	
	private static final long serialVersionUID = 1L;
	
	private Long total;
	
	private List<T> rows;
	
	public PageResult(Long total, List<T> rows) {
		super();
		this.total = total;
		this.rows = rows;
	}
	
	
}
