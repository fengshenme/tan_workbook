package tan.wei.feng.model.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

/**
 * 文件路径实体 
 * @author 1015956962@163.com
 *
 */
@Entity
@Table(name="tb_userfile")
public @Data class UserFile implements Serializable{
	
	private static final long serialVersionUID = 6229118033505587669L;
	
	@Id
	private Long id ;
	private Long userid;
	private String fileurl;
	private Date addtime;
	private Integer filetype ;

	
}
