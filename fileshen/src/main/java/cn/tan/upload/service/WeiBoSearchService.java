package cn.tan.upload.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import cn.tan.upload.entity.WeiBoSearch;
import cn.tan.upload.mapper.WeiBoSearchMapper;


@Component
public class WeiBoSearchService {
	
	
	 private final WeiBoSearchMapper weiBoSearchMapper;
	
	@Autowired
	public WeiBoSearchService(WeiBoSearchMapper weiBoSearchMapper) {
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
}
