package tan.wei.feng.entity;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 评论模型
 * @author 锋什么
 *
 */
@Entity
@Table(name="tb_remark")
public @Data class Remark implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	/**
	 * id中有评论创建时间
	 */
	@Id 
	private Long id ;
	/**
	 * 文章id
	 */
	private Long articleId;
	/**
	 * 用户id
	 */
	private Long userId;
	/**
	 * 用户名
	 */
	private String userName;
	/**
	 *  评论内容
	 */
	private String content;
	
}
