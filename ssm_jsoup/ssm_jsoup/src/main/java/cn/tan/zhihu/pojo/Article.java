package cn.tan.zhihu.pojo;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * 知乎爬虫数据库
 * @author 10159
 *
 */
@Entity
@Table(name="tb_article")
public class Article implements Serializable{
	private static final long serialVersionUID = 1L;
	
	@Id
    private Long id;

	private String columnid;

    private String userid;

    private String title;

    private Date createtime;

    private Integer visits;

    private Integer thumbup;

    private Integer comment;

    private String url;

    private String content;


    public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id ;
	}

	public String getColumnid() {
		return columnid;
	}

	public void setColumnid(String columnid) {
		this.columnid = columnid;
	}

	public String getUserid() {
		return userid;
	}

	public void setUserid(String userid) {
		this.userid = userid;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public Date getCreatetime() {
		return createtime;
	}

	public void setCreatetime(Date createtime) {
		this.createtime = createtime;
	}

	public Integer getVisits() {
		return visits;
	}

	public void setVisits(Integer visits) {
		this.visits = visits;
	}

	public Integer getThumbup() {
		return thumbup;
	}

	public void setThumbup(Integer thumbup) {
		this.thumbup = thumbup;
	}

	public Integer getComment() {
		return comment;
	}

	public void setComment(Integer comment) {
		this.comment = comment;
	}

	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	@Override
	public String toString() {
		return "Article [id=" + id + ", columnid=" + columnid + ", userid=" + userid + ", title=" + title
				+ ", createtime=" + createtime + ", visits=" + visits + ", thumbup=" + thumbup + ", comment=" + comment
				+ ", url=" + url + ", content=" + content + "]";
	}
	
}