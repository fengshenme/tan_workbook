package tan.wei.feng.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

@Entity
@Table(name="weibosearch")
public @Data class WeiBoSearch implements Serializable{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@Id
	private String userid ;
	//微博内容
	private String content;
	//添加时间
	private Date addtime;
	//昵称
	private String nickname;
	//微博网址
	private String weibourl;
	// 是否内容相关
	private Integer labels;
	// 使用手机
	private String employphone;
	
	
	
	public String toCsv() {
		return userid + "` " + content + "` " + addtime + "` "
				+ nickname + "` " + weibourl + "`" + labels + "` " + employphone;
	}
	
}
