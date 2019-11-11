package cn.tan.upload.controller;

import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import cn.tan.upload.service.VideoService;

/**
 * 视频控制层
 * @author 10159
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/video")
public class VideoController {
	
	private final VideoService videoService;
	@Autowired 
	public VideoController(VideoService videoService) {
		this.videoService = videoService;
	}

	/**
	 * 单个视频播放
	 * @param fileName
	 * @param filePath
	 * @return
	 * @throws IOException
	 */
	@GetMapping(value = "/fileVideo/{fileId}")
	public ResponseEntity<Resource> fileVideoExport(@PathVariable String fileId) throws IOException {  
	        return videoService.findByVideourl(fileId);   
    }
	
}
