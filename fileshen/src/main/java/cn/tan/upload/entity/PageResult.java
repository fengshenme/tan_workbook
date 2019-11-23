package tan.wei.feng.entity;

import java.util.List;

/**
 * 分页结果类
 * @author 1
 * @param <T>
 *
 */
public class PageResult<T> {
	
	private Long total;
	private List<T> rows;
	private String fileid;
	
	
	public PageResult(Long total, String fileid) {
		super();
		this.total = total;
		this.fileid = fileid;
	}

	public String getFileid() {
		return fileid;
	}

	public void setFileid(String fileid) {
		this.fileid = fileid;
	}

	public PageResult() {
		super();
	}

	public PageResult(Long total, List<T> rows) {
		super();
		this.total = total;
		this.rows = rows;
	}
	
	public Long getTotal() {
		return total;
	}
	public void setTotal(Long total) {
		this.total = total;
	}
	public List<T> getRows() {
		return rows;
	}
	public void setRows(List<T> rows) {
		this.rows = rows;
	}
	
}
