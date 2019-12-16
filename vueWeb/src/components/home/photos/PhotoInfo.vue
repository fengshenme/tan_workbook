<template>
    <div class="photoinfo-container">
       <h3>{{photoinfo.title}}</h3> 
       <p class="subtitle">
            <span>发表时间:{{photoinfo.add_time | dateFormat}}</span>
            <span>点击数:{{photoinfo.click}}</span>
       </p>
       <hr>

       <!-- 缩略图区域 -->
       <div class="thumbs">
            <vue-preview :slides="list" @close="handleClose" ></vue-preview>
        </div>

        
       <!-- 图片内容区域 -->
       <div class="content" v-html="photoinfo.content"></div>
        


       <!-- 放置现成的评论子组件 -->
       <cmt-box :id="id"></cmt-box>
    </div>
</template>

<script>
import {Toast} from 'mint-ui'
// 导入子组件
import comment from "@/components/subcomponents/comment.vue"
import mobileApi from '@/api/mobileapi'
export default {
    data(){
        return {
            id:this.$route.params.id,// 从路由中获取的图片id
            photoinfo: {}, // 图片详情
            list: [] // 缩略图数组
        };
    },
    created(){
        this.getPhotoInfo();
        this.getThumbs();
    },
    methods:{
        getPhotoInfo(){
            mobileApi.getimageInfo(this.id).then(result => {
                if (result.data.status === 0) {
                    this.photoinfo = result.data.message[0];
                } else {
                    Toast('图片详情获取失败')    
                }
            });
        },
        getThumbs(){
            // 获取缩略图
            mobileApi.getthumimages(this.id).then(result => {
                if(result.data.status === 0){
                    // 循环每个图片数据,补全图片的宽与高
                    result.data.message.forEach(element => {
                        element.w = 1200;
                        element.h = 800;
                        element.msrc = element.src;
                    });
                    // 把完整的数据保存到list中
                    this.list = result.data.message;
                }else{
                    // 失败的
                    Toast('加载轮播图失败...');
                }
            });
        },
        handleClose () {
        }
    },
    components:{ //注册子组件
        'cmt-box':comment,
    }
}
</script>

<style lang="scss" scoped>
.photoinfo-container{
    padding: 3px;
    h3{
        color: #26a2ff;
        font-size: 15px;
        text-align: center;
        margin: 15px o;
    }
    .subtitle{
        display: flex;
        justify-content: space-between;
        font-size: 13px;
    }

    .content{
        font-size: 13px;
        line-height: 30px;
    }
    hr{
        color: #ccc;
    }
    .thumbs{
        display: flex;
        // margin: 10px;
        // box-shadow: 0 0 10px #999 ;
    }
}

</style>