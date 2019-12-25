<template>
    <div>
        <ul class="mui-table-view" v-for="item in newslist" :key="item.id" >
            <li class="mui-table-view-cell mui-media"   >
                <router-link :to="'/home/newsinfo/' + item.id">
                    <img class="mui-media-object mui-pull-left" :src="item.img_url">
                    <div class="mui-media-body">
                        <h2>{{item.title}}</h2>
                        <p class='mui-ellipsis'>
                            <span>发表时间:  {{item.createtime | dateFormat }}</span>
                            <span>阅读: {{item.visits===null ? 0:item.visits }}次</span>
                        </p>
                    </div>
                </router-link>
            </li>
		</ul>
        <button class="button-len" @click="loadMore">加载更多</button>
    </div>
</template>
<script>
import {Toast} from 'mint-ui'
import mobileApi from '@/api/mobileapi'
import "@/assets/css/fileweb.css"
export default {
    // directives: { InfiniteScroll },
    data() {
        return {
            // 新闻列表
            newslist:[],
            page: 1,
            loading: false
        };
    },
    created(){ // 生命周期函数
        this.getNewsList(this.page);
    },
    methods: {
        // 获取新闻列表
        getNewsList(page){
            mobileApi.getnewslist(page).then(result => {
                if(result.data.code === 0){
                    this.newslist = this.newslist.concat(result.data.data)
                }else{
                    // 失败的
                    Toast('获取新闻列表失败...');
                }
            })
        },
        loadMore() {
            this.page = this.page + 1
             // 缓冲
            this.getNewsList(this.page,this.pagesize)
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