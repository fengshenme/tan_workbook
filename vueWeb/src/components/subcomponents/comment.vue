<template>
    <div class="cmt-container">
        <h3>发表评论</h3>
        <hr>
        <textarea rows="2" placeholder="请输入要BB的内容(做多吐槽120字)" maxlength="120" v-model="msg"></textarea>
        <mt-button type="primary" size="large"  @click="postComment">发表评论</mt-button>
        <div class="cmt-list">
            <div class="cmt-item" v-for="(item,i) in comments" :key="item.add_time">
                <div class="cmt-title">
                    第{{i+1}}楼&nbsp;&nbsp;用户:{{item.userName}}&nbsp;&nbsp;发表时间:{{Number(item.id.toString().substring(0,13)) | dateFormat}}
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
import {Toast,Button} from 'mint-ui'
import {getcomments,postcomment} from '@/api/mobileapi'
import { getUser } from '@/utils/common'
export default {
    components:{'mt-button':Button},
    props:['id'] ,
    data(){
        return {
            pageIndex: 1, // 默认展示第一页数据
            pagesize:5,
            comments: [], // 所有的评论数据
            msg: "", // 评论输入的内容
            cmt: {},
        };
    },
    created(){
        this.getComments();
    },
    methods:{
        getComments(){ // 获取评论
            getcomments(this.id, this.pageIndex, this.pagesize).then(result => {
                if(result.status===200){
                   this.comments = this.comments.concat(result.data);
                }else{
                    Toast("获取评论失败");
                }
            });
        },
        getMore(){ 
            this.pageIndex++;
            this.getComments();
        },
        postComment(){
            // 校验是否为空
            if(this.msg.trim().length === 0 ){
                return Toast('评论内容不能为空!');
            }
            // 发表评论
            // 1.拼接出一个评论对象
            const cmt = {
                        userName:getUser().name,
                        addTime: Date.now() ,
                        content: this.msg.trim()
                    };
            postcomment(this.$route.params.id, cmt).then(response => {
                if(response.status === 200){
                    // 评论成功插入对象数组中
                    this.comments.unshift(cmt);
                    this.msg = "";
                    Toast(response.data)
                    location.reload();
                }else{
                    Toast('评论失败');
                }
            });
        }
    }
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