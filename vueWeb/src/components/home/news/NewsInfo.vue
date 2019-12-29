<template>
    <div class="newsinfo-container">
        <!-- 大标题 -->
        <h3 class="title">{{newsinfo.title}}</h3>
        <!-- 子标题 -->
        <p class="subtitle">
            <span>发表时间:{{newsinfo.createtime | dateFormat}}</span>
            <span>阅读数:{{newsinfo.visits===null ? 0 : newsinfo.visits}}</span>
        </p>
        <hr>
        <!-- 内容区域 -->
        <div class="content" v-html="newsinfo.content"></div>
        <!-- 评论区域 -->
        <comment-box :id="this.id"></comment-box>
    </div>
</template>
<script>
import {Toast} from 'mint-ui'
import comment from '@/components/subcomponents/comment.vue'
import {getNewIn} from '@/api/mobileapi'
export default {
    components:{
        // 用来注册评论子组件
        "comment-box": comment
    },
    data(){
        return{
            // 将url地址中id值挂载到data中,方便以后调用
            id: this.$route.params.id,
            newsinfo: {} // 新闻对象
        }
    },
    created(){
        this.getNewsInfo()
    },
    methods: {
        getNewsInfo(){
            // 获取新闻详情
            getNewIn(this.id).then(result => {
                if(result.status === 200){
                    // 成功
                    this.newsinfo = result.data;
                }else{
                    // 失败的
                    Toast('获取新闻失败...');
                }
            });
        }
    }
    
}
</script>
<style lang="scss" >
.newsinfo-container{
    padding:0 4px;
    .title{
        font-size: 16px;
        text-align: center;
        margin: 10px 0;
        color: rgba(255, 0, 0, 0.856);
    }
    .subtitle{
        font-size: 13px;
        color: cornflowerblue;
        display: flex;
        justify-content: space-between;
    }
    .content{
        img{
            width: 100%;
        }
    }
}
    
</style>