package tan.wei.feng.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 文件路径实体 
 * @author 锋什么
 *
 */
@Entity
@Table(name="tb_userfile")
public @Data class UserFile implements Serializable{
	
	private static final long serialVersionUID = 1L;
	
	@Id
	private Long id ;
	private Long userid;
	private String fileurl;
	private Date addtime;
	private Integer filetype ;

	
}
