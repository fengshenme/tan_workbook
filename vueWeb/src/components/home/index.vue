<template>
    <div>
        <!-- 轮播图子组件 -->
        <swiper :lunbotuList="lunbotuList" :isfull="true"></swiper>

        <ul class="mui-table-view mui-grid-view mui-grid-9">
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <router-link to="/home/newslist" >
                    <img src="@/assets/images/新闻资讯.png" alt="">
                    <div class="mui-media-body">新闻资讯</div>
                </router-link >
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <router-link to="/home/photolist">
                    <img src="@/assets/images/图片分享.png" alt="">
                    <div class="mui-media-body">图片分享</div>
                </router-link>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <router-link to="/home/goodslist">
                    <img src="@/assets/images/商品购买.png" alt="">
                    <div class="mui-media-body">商品购买</div>
                </router-link>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <a href="#">
                    <img src="@/assets/images/留言反馈.png" alt="">
                    <div class="mui-media-body">留言反馈</div>
                </a>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <a href="#">
                    <img src="@/assets/images/视频专区.png" alt="">
                    <div class="mui-media-body">视频专区</div>
                </a>
            </li>
            <li class="mui-table-view-cell mui-media mui-col-xs-4 mui-col-sm-3">
                <a href="#">
                    <img src="@/assets/images/联系我们.png" alt="">
                    <div class="mui-media-body">联系我们</div>
                </a>
            </li>
        </ul> 
    </div>
</template>
<script>
import { removeUser } from '@/utils/common'
import {Toast} from 'mint-ui'
import swiper from "@/components/subcomponents/swiper.vue"
import {indexImg} from '@/api/file'
import {httpUrl} from '@/utils/request'
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
            indexImg(6).then(response => {
                switch (response.status) {
                    case 200:
                        response.data.forEach(element => {
                            this.lunbotuList.push(httpUrl.concat("img/file/").concat(element))
                        });
                        break;
                    case 206:
                        response.data.forEach(element => {
                            this.lunbotuList.push(httpUrl.concat("img/file/").concat(element))
                        });
                        removeUser()
                        this.$store.commit('ismobile',undefined)
                        break;
                    default:
                        Toast("获取轮播图失败")
                        break;
                }
                    
            });
            console.log('object :', this.lunbotuList);
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

