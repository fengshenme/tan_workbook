package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.Testinsert;

/**
 * 实验仓库
 * @author 锋什么
 *
 */
@Repository
public interface TestMapper extends JpaRepository<Testinsert,Long>{

}
