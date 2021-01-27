package tan.wei.feng.model.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 文章实体类
 * @author 1015956962@163.com
 *
 */
@Entity
@Table(name="tb_article")
public @Data class Article implements Serializable{
	
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

}
