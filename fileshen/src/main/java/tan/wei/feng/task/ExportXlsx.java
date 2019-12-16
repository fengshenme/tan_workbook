package tan.wei.feng.task;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import tan.wei.feng.entity.Article;
import tan.wei.feng.service.read.ArticleFindService;

/**
 * 导出xlsx
 * @author 10159
 *
 */
@Component
public class ExportXlsx {
	
	@Autowired
	private ArticleFindService articleFindService = null;
	
	/**
	 * 导出xlsx
	 * @throws IOException
	 */
	//@Scheduled(cron = "30 39 * * * ?")
	public void exportxlsx () throws IOException {
		List<Article> articles = articleFindService.findAll();
	    int rownum = 1;
	    //创建一个工作薄
	    try(Workbook wks = new HSSFWorkbook();) {
	    	//创建一个sheet页
	        Sheet sh= wks.createSheet("sheet1");
	    	for (Article article : articles) {
		      //创建第一行
		        Row row= sh.createRow(rownum);
		        //创建第一行第1个单元格并赋值
		        row.createCell(0).setCellValue(article.getColumnid());
		      //创建第一行第2个单元格并赋值
		        row.createCell(1).setCellValue(article.getTitle().concat(article.getContent()));
		        rownum ++;
	        }
	    	FileOutputStream out= new FileOutputStream("H:/blogs.xlsx");
	        wks.write(out);
	        out.close();
	    }
	    
	}
	
	
}
