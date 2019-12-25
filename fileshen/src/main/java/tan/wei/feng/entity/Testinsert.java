package tan.wei.feng.entity;

import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "test_insert")
public class Testinsert {
	
	@Id
	private Long id;
	private Long number;
	private Date addtime;
	
	
	
	
	@Override
	public String toString() {
		return "Testinsert [id=" + id + ", number=" + number + ", addtime=" + addtime + "]";
	}
	
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public Long getNumber() {
		return number;
	}
	public void setNumber(Long number) {
		this.number = number;
	}
	public Date getAddtime() {
		return addtime;
	}
	public void setAddtime(Date addtime) {
		this.addtime = addtime;
	}
	
	
	
}
