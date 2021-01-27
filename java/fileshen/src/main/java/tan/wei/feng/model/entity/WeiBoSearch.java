package tan.wei.feng.model.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 微博搜索数据模型
 * @author 1015956962@163.com
 *
 */
@Entity
@Table(name="tb_weibosearch")
public @Data class WeiBoSearch implements Serializable{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@Id
	private String userid ;
	/**
	 * 微博内容
	 */
	private String content;
	/**
	 * 添加时间
	 */
	private Date addtime;
	/**
	 * 昵称
	 */
	private String nickname;
	/**
	 * 微博网址
	 */
	private String weibourl;
	/**
	 *  是否内容相关
	 */
	private Integer labels;
	/**
	 *  使用手机
	 */
	private String employphone;
	
	
	
	public String toCsv() {
		return userid + "` " + content + "` " + addtime + "` "
				+ nickname + "` " + weibourl + "`" + labels + "` " + employphone;
	}
	
}
