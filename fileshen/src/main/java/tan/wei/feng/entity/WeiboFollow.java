package tan.wei.feng.entity;

import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

@Entity
@Table(name = "weibofollow")
public @Data class WeiboFollow {
	
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
