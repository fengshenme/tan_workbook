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
      <pagination v-show="total>=0" :total="total" :page.sync="listQuery.page" 
          :limit.sync="listQuery.limit" @pagination="fetchList" />
      
  
</div>

</template>

<script>
import fileApi from '@/api/file'
import {Toast} from 'mint-ui'
// 分页
import Pagination from '@/components/subcomponents/Page'
import {httpUrl} from '@/utils/common'
import { MessageBox } from 'element-ui'
export default {
    data() {
      return {
        baseurl: httpUrl,
        fileList:[],
        srcList:[],
        total: 0,
        listQuery: {
          page: 1,
          limit: 10
        },
      }
    },
    components: { Pagination },
    created() {
       this.fetchList();
    },
    methods: {
      fetchList(){
        const filetype = 1;
        this.fileList = [];
        this.srcList = [];
        fileApi.fetchList(this.listQuery,filetype).then(response => {
            Toast(response.data.message)
          response.data.data.rows.forEach(element => {
                  const fileurl = this.baseurl.concat("img/file/").concat(element.id)
                  const filedown = this.baseurl.concat("api/fileDownload/").concat(element.id)
                  this.fileList.push({url:fileurl,fileid:element.id,addtime:element.addtime,filedownurl:filedown})
                  this.srcList.push(fileurl)
                });
          this.total = response.data.data.total
        })
     },
      delFile(id){
        MessageBox.confirm('此操作将永久删除该文件, 是否继续?', '提示', {
          confirmButtonText: '确定',
          cancelButtonText: '取消',
          type: 'warning',
          center: true,
        }).then(() => {
          fileApi.delFile(id).then(res => {
            if(res.data.code === 0){
              Toast('删除成功' );
              location.reload();
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

