package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.Testinsert;

/**
 * 测试
 * @author 10159
 *
 */
@Repository
public interface TestMapper extends JpaRepository<Testinsert,Long>{

}
