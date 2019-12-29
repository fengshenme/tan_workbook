package tan.wei.feng.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 微博数据模型
 * @author 锋什么
 *
 */
@Entity
@Table(name = "tb_weibofollow")
public @Data class WeiboFollow implements Serializable{
	
	private static final long serialVersionUID = 1L;
	
	@Id
	private Long id;
	private String userid;
	private String friendid;
	private String userurl;
	private String friendurl;
	private String friendinfo;
	private String sex;
	private String nickname;
	private String followfans;
	private Date addtime;
	
	/**
	 * 插入csv用
	 * @return
	 */
	public String toCsv() {
		return id + "` " + userid + "` " + friendid + "` " + userurl
				+ "` " + friendurl + "` " + friendinfo + "` " + sex + "` " + nickname
				+ "` " + followfans + "` " + addtime ;
	}
	
}
