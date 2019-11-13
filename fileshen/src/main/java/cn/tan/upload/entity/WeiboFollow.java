package cn.tan.upload.entity;

import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "weibofollow")
public class WeiboFollow {
	
	@Id
	private String id;
	private String userid;
	private String friendid;
	private String userurl;
	private String friendurl;
	private String friendinfo;
	private String sex;
	private String nickname;
	private String followfans;
	private Date addtime;
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getUserid() {
		return userid;
	}
	public void setUserid(String userid) {
		this.userid = userid;
	}
	public String getFriendid() {
		return friendid;
	}
	public void setFriendid(String friendid) {
		this.friendid = friendid;
	}
	public String getUserurl() {
		return userurl;
	}
	public void setUserurl(String userurl) {
		this.userurl = userurl;
	}
	public String getFriendurl() {
		return friendurl;
	}
	public void setFriendurl(String friendurl) {
		this.friendurl = friendurl;
	}
	public String getFriendinfo() {
		return friendinfo;
	}
	public void setFriendinfo(String friendinfo) {
		this.friendinfo = friendinfo;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getNickname() {
		return nickname;
	}
	public void setNickname(String nickname) {
		this.nickname = nickname;
	}
	public String getFollowfans() {
		return followfans;
	}
	public void setFollowfans(String followfans) {
		this.followfans = followfans;
	}
	public Date getAddtime() {
		return addtime;
	}
	public void setAddtime(Date addtime) {
		this.addtime = addtime;
	}
	@Override
	public String toString() {
		return "WeiboFollow [id=" + id + ", userid=" + userid + ", friendid=" + friendid + ", userurl=" + userurl
				+ ", friendurl=" + friendurl + ", friendinfo=" + friendinfo + ", sex=" + sex + ", nickname=" + nickname
				+ ", followfans=" + followfans + ", addtime=" + addtime + "]";
	}
	
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
