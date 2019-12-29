package tan.wei.feng.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import tan.wei.feng.entity.WeiBoSearch;
import tan.wei.feng.entity.WeiboFollow;
import tan.wei.feng.mapper.WeiBoFollowMapper;
import tan.wei.feng.mapper.WeiBoSearchMapper;

/**
 * 微博搜索数据服务
 * @author 锋什么
 *
 */
@Component
public class WeiBoSearchService {
	
	
	 private final WeiBoSearchMapper weiBoSearchMapper;
	 private final WeiBoFollowMapper weiBoFollowMapper;
	
	@Autowired
	public WeiBoSearchService(WeiBoSearchMapper weiBoSearchMapper,WeiBoFollowMapper weiBoFollowMapper) {
		this.weiBoFollowMapper = weiBoFollowMapper;
		this.weiBoSearchMapper = weiBoSearchMapper;
	}


	/**
	 * 增加
	 * @param weibo
	 */
	public void save(WeiBoSearch weibo) {
		weiBoSearchMapper.save(weibo);
	}
	
	/**
	 * 查询
	 * @return
	 */
	public List<WeiBoSearch> findAll() {
		return weiBoSearchMapper.findAll();
	}

	/**
	 * 增加好友信息
	 * @param weiboFollow
	 */
	public void saveFollow(WeiboFollow weiboFollow) {
		 weiBoFollowMapper.save(weiboFollow);
	}
	
	/**
	 * 查询好友信息
	 * @return
	 */
	public List<WeiboFollow> findFollowAll(){
		return weiBoFollowMapper.findAll();
	}
	
}
