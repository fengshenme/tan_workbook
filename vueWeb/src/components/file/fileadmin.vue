<template>
<div >
			<ul class="mui-table-view" v-for="item in fileList" :key="item.fileid">
				<li class="mui-table-view-cell mui-media">
						<img class="mui-media-object mui-pull-left" :src="item.url" alt="" >
						<div class="mui-media-body">
							幸福 <span>{{item.addtime | dateFormat}}</span> 
              <button id='confirmBtn' class="mui-btn mui-btn-danger mui-btn-outlined mui-pull-right" @click="delFile(item.fileid)" >删除</button>
							<p class='mui-ellipsis'>{{item.url}}</p>
						</div>
				</li>
			</ul>
      <!-- 分页 -->
      <el-pagination
      v-show="total>=0"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
      :current-page="page"
      :page-size="pageSize"
      layout="total, sizes, prev, pager, next, jumper"
      :page-sizes="[10,20,30,40]"
      :total="total"
    />
  
</div>

</template>

<script>
import 'element-ui/lib/theme-chalk/index.css';
import {FetchList,DelFile} from '@/api/file'
import {Toast} from 'mint-ui'
import {httpUrl} from '@/utils/request'
import { MessageBox , Pagination } from 'element-ui'
export default {
    data() {
      return {
        baseurl: httpUrl,
        fileList:[],
        srcList:[],
        total: 0,
        page: 1,
        pageSize: 10
      }
    },
    components: {
    'el-pagination':Pagination
  },
    created() {
       this.fetchList(this.page,this.pageSize);
    },
    methods: {
      handleSizeChange(val) {
        this.fetchList(this.page,val)
      },
      handleCurrentChange(val) {
        this.fetchList(val,this.pageSize)
      },
      fetchList(page,pageSize){
        const filetype = 1;
        this.fileList = [];
        this.srcList = [];
        FetchList(filetype,page,pageSize).then(response => {
          response.data.rows.forEach(element => {
                  const fileurl = this.baseurl.concat("img/file/").concat(element.id)
                  const filedown = this.baseurl.concat("api/fileDownload/").concat(element.id)
                  this.fileList.push({url:fileurl,fileid:element.id,addtime:element.addtime,filedownurl:filedown})
                  this.srcList.push(fileurl)
                });
          this.total = response.data.total
        })
     },
      delFile(id){
        MessageBox.confirm('此操作将永久删除该文件, 是否继续?', '提示', {
          confirmButtonText: '确定',
          cancelButtonText: '取消',
          type: 'warning',
          center: true,
        }).then(() => {
          DelFile(id).then(res => {
            if(res.status === 200 ){
              Toast('删除成功' );
              location.reload();
            }
            if(res.status === 205){
              Toast('删除失败');
            }
          })
        }).catch(() => {
          Toast( '已取消删除'  )
        })
      },
    }

}
</script>


<style lang="scss" scoped>
  .el-header {
    background-color: #B3C0D1;
    color: #333;
    line-height: 60px;
  }
  
  .el-aside {
    color: #333;
   
  }
  


</style>

