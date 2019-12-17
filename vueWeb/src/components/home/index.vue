<template>
    <div>
        <!-- 轮播图子组件 -->
        <swiper :lunbotuList="lunbotuList" :isfull="true"></swiper>

        <ul class="mui-table-view mui-grid-view mui-grid-9">
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <router-link to="/home/newslist" >
                    <img src="@/assets/images/menu1.png" alt="">
                    <div class="mui-media-body">新闻资讯</div>
                </router-link >
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <router-link to="/home/photolist">
                    <img src="@/assets/images/yuantiao.jpg" alt="">
                    <div class="mui-media-body">图片分享</div>
                </router-link>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <router-link to="/home/goodslist">
                    <img src="@/assets/images/menu3.png" alt="">
                    <div class="mui-media-body">商品购买</div>
                </router-link>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <a href="#">
                    <img src="@/assets/images/menu4.png" alt="">
                    <div class="mui-media-body">留言反馈</div>
                </a>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <a href="#">
                    <img src="@/assets/images/menu5.png" alt="">
                    <div class="mui-media-body">视频专区</div>
                </a>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <a href="#">
                    <img src="@/assets/images/menu6.png" alt="">
                    <div class="mui-media-body">联系我们</div>
                </a>
            </li>
        </ul> 
    </div>
</template>
<script>
import {Toast} from 'mint-ui'
import swiper from "@/components/subcomponents/swiper.vue"
import file from '@/api/file'
import {httpUrl} from '@/utils/common'
export default {
    data() {
        return {
            lunbotuList:[],
        };
    },
    created(){
         this.getlunbotu();
    },
    methods: {
        // 获取轮播图数据的方法 ，filetype为6
        getlunbotu(){
            file.fileShowList(6).then(response => {
                if (parseInt(response.data.code) === 0) {
                    response.data.data.forEach(element => {
                        this.lunbotuList.push(httpUrl.concat("img/file/").concat(element))
                    });
                } else {
                    Toast(response.data.message)
                }
                
            });
        }
    },
    components: {
        swiper,
    }
}
</script>

<style lang="scss" scoped>

.mui-grid-view.mui-grid-9 {
  background-color: #fff;
  border: none;
  img {
    width: 60px;
    height: 60px;
  }

  .mui-media-body{
    font-size: 13px;
  }
}

.mui-grid-view.mui-grid-9 .mui-table-view-cell {
  border: 0;
}
</style>

