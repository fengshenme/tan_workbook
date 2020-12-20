package org.web.demo.pojo;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * 文章实体类
 * @author 1015956962@163.com
 *
 */
@Entity
@Table(name="tb_article")
public class Article implements Serializable{
	
	private static final long serialVersionUID = 6817580263901341262L;
	
	/**
	 * ID
	 */
	@Id
	private Long id;
	/**
	 * 专栏ID 
	 */
	private Integer columnid;
	/**
	 * 用户ID
	 */
	private String userid;
	/**
	 * 标题
	 */
	private String title;
	/**
	 * 文章正文
	 */
	private String content;
	/**
	 * 发表日期
	 */
	private Date createtime;
	/**
	 * 浏览量
	 */
	private Integer visits;
	/**
	 * 评论数
	 */
	private Integer comment;
	/**
	 * URL
	 */
	private String url;

	

	public static long getSerialversionuid() {
		return serialVersionUID;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public Integer getColumnid() {
		return columnid;
	}

	public void setColumnid(Integer columnid) {
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

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
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

}
