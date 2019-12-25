package tan.wei.feng.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

@Entity
@Table(name="user")
public @Data class User implements Serializable{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
	private Long userid;
	
	private String password;
	// 昵称
	private String nickname;
	
	private String mobile ;

	private String email;
	
	private String address;
	
	private int sex ;
	
	@Column(name="update_time")
	private Date updatetime;
	
	
}
