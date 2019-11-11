package cn.tan.upload.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="weibosearch")
public class WeiBoSearch implements Serializable{
	
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
	
	public String getUserid() {
		return userid;
	}
	public void setUserid(String userid) {
		this.userid = userid;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public Date getAddtime() {
		return addtime;
	}
	public void setAddtime(Date addtime) {
		this.addtime = addtime;
	}
	public String getNickname() {
		return nickname;
	}
	public void setNickname(String nickname) {
		this.nickname = nickname;
	}
	public String getWeibourl() {
		return weibourl;
	}
	public void setWeibourl(String weibourl) {
		this.weibourl = weibourl;
	}
	public Integer getLabels() {
		return labels;
	}
	public void setLabels(Integer labels) {
		this.labels = labels;
	}
	public String getEmployphone() {
		return employphone;
	}
	public void setEmployphone(String employphone) {
		this.employphone = employphone;
	}
	@Override
	public String toString() {
		return "WeiBoSearch [userid=" + userid + ", content=" + content + ", addtime=" + addtime + ", nickname="
				+ nickname + ", weibourl=" + weibourl + ", labels=" + labels + ", employphone=" + employphone + "]";
	}
	
	public String toCsv() {
		return userid + "` " + content + "` " + addtime + "` "
				+ nickname + "` " + weibourl + "`" + labels + "` " + employphone;
	}
	
}
