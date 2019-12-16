<template>
    <div class="cmt-container">
        <h3>发表评论</h3>
        <hr>
        <textarea rows="2" placeholder="请输入要BB的内容(做多吐槽120字)" maxlength="120" v-model="msg"></textarea>
        <mt-button type="primary" size="large"  @click="postComment">发表评论</mt-button>
        <div class="cmt-list">
            <div class="cmt-item" v-for="(item,i) in comments" :key="item.add_time">
                <div class="cmt-title">
                    第{{i+1}}楼&nbsp;&nbsp;用户:{{item.user_name}}&nbsp;&nbsp;发表时间:{{item.add_time | dateFormat}}
                </div>
                <div class="cmt-body">
                    {{item.content==='undefined' ? '此用户很懒,没有说':item.content}}
                </div>
            </div>
        </div>
        <mt-button type="danger" size="large" plain @click="getMore">加载更多</mt-button>
    </div>
</template>

<script>
import {Toast} from 'mint-ui'
import mobileApi from '@/api/mobileapi'
export default {
    data(){
        return {
            pageIndex: 1, // 默认展示第一页数据
            pagesize:5,
            comments: [], // 所有的评论数据
            msg: "", // 评论输入的内容
            cmt: {}
        };
    },
    created(){
        this.getComments();
    },
    methods:{
        getComments(){ // 获取评论
            mobileApi.getcomments(this.id, this.pageIndex, this.size).then(result => {
                if(result.data.status===0){
                   //this.comments = result.body.message;
                   // 采用拼接,这样就不会把老数据清空
                   this.comments = this.comments.concat(result.data.message);
                }else{
                    Toast("获取评论失败");
                }
            });
        },
        getMore(){ // 获取更多
            this.pageIndex++;
            this.getComments();
        },
        postComment(){
            // 校验是否为空
            if(this.msg.trim().length === 0 ){
                return Toast('评论内容不能为空!');
            }
            // 发表评论
            // 参数1: 请求的url地址Error in v-on handler: "ReferenceError: cmt is not defined
            // 参数2: 提交给服务器的数据对象 {content: this.msg }
            // 参数3: 定义提交时候,表单中数据的格式 {emulateJSON:true},已经全局配置不用再加入
            // 1.拼接出一个评论对象
            const cmt = {
                        user_name:"匿名用户",// 后期有登录功能时从session中取出用户名
                        add_time: Date.now() ,
                        content: this.msg.trim()
                    };        
            mobileApi.postcomment(this.$route.params.id, {content: this.msg.trim()}).then(result => {
                if(result.data.status === 0){
                    // 评论成功插入对象数组中
                    this.comments.unshift(cmt);
                    this.msg = "";
                }else{
                    Toast('评论失败');
                    // this.msg = "";
                }
            });
        }
    },
    props:['id']
}
</script>

<style lang="scss" scoped>
.cmt-container{
    
    h3{
        font-size: 18px;
    }
    textarea{
        font-size: 14px;
        height: 80px;
        margin: 0;
    }
    .cmt-list{
        margin: 5px 0;
        .cmt-item{
            font-size: 14px;
            .cmt-title{
                line-height: 30px;
                background-color: #ccc
            }
            .cmt-body{
                line-height: 30px;
                text-indent: 2em;
            }
        }
    }
    hr{
        color: #ccc;
    }
}
</style>