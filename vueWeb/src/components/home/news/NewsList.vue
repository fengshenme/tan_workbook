<template>
    <div>
        <ul class="mui-table-view" v-for="item in newslist" :key="item.id">
            <li class="mui-table-view-cell mui-media">
                <router-link :to="'/home/newsinfo/' + item.id">
                    <img class="mui-media-object mui-pull-left" :src="item.img_url">
                    <div class="mui-media-body">
                        <h2>{{item.title}}</h2>
                        <p class='mui-ellipsis'>
                            <span>发表时间:  {{item.createtime | dateFormat }}</span>
                            <span>点击: {{item.visits}}次</span>
                        </p>
                    </div>
                </router-link>
            </li>
		</ul>
        
    </div>
</template>
<script>
import {Toast} from 'mint-ui'
import mobileApi from '@/api/mobileapi'
export default {
    data() {
        return {
            // 新闻列表
            newslist:[],
            page: 1,
            pagesize: 10
        };
    },
    created(){ // 生命周期函数
         this.getNewsList();
    },
    methods: {
        // 获取新闻列表
        getNewsList(){
            mobileApi.getnewslist(this.page,this.pagesize).then(result => {
                if(result.data.code === 0){
                    // 成功
                    this.newslist = result.data.data;
                }else{
                    // 失败的
                    Toast('获取新闻列表失败...');
                }
            })
        }
    }
}
</script>

<style lang="scss" scoped>
.mui-table-view{
    li{
        h2{font-size: 14px}
        .mui-ellipsis{
            font-size: 12px;
            color:#226aff;
            display: flex;
            justify-content: space-between;
        }
    }
}
</style>