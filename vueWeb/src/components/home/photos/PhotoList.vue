<template>
    <div>
        <!-- 顶部滑动模块 -->
        <div id="slider" class="mui-slider">
            <div id="sliderSegmentedControl" class="mui-scroll-wrapper mui-slider-indicator mui-segmented-control mui-segmented-control-inverted">
                <div class="mui-scroll">
                    <a :class="['mui-control-item',item.id == 0 ? 'mui-active': '']"
                     v-for="item in cates" :key="item.id" @click="getPhotoListByCateId(item.id)">
                        {{item.title}}
                    </a>
                </div>
            </div>
        </div>
        <!-- 图片列表区域 -->
        <ul class="photo-list">
            <router-link v-for="item in list" :key="item.id" :to="'/home/photoinfo/' + item.id" tag="li">
                <img v-lazy="item.img_url">
                <div class="info">
                    <h1 class="info-title">{{item.title}}</h1>
                    <div class="info-body">{{item.abstract}}</div>
                </div>
            </router-link>
        </ul>
    </div>
</template>

<script>
// 导入mui
import mui from '@/assets/js/mui.min.js'
import {Toast} from 'mint-ui'
import mobileApi from '@/api/mobileapi'
export default {
    data(){
        return {
            cates: [] ,// 所有分类的列表数组
            list: [] // 图片列表数组
        };
    },
    created(){
        this.getAllCategory();
        this.getPhotoListByCateId(0);
    },
    mounted(){
        // 初始化滑动控件
        // 当组件中的DOM结构被渲染好并放到页面中后，会执行这个 钩子函数
        // 如果要操作元素了，最好在 mounted 里面，因为，这里时候的 DOM 元素 是最新的
        mui('.mui-scroll-wrapper').scroll({
            deceleration: 0.0005 //flick 减速系数，系数越大，滚动速度越慢，滚动距离越小，默认值0.0006
        });
    },
    methods:{
        getAllCategory(){
            // 获取所有的图片分类
            mobileApi.getimgcategory().then(result => {
                if (result.data.status === 0) {
                    // 手动拼接出一个最完整的分类列表
                    result.data.message.unshift({ title: '全部',id: 0 })
                    this.cates = result.data.message ;
                } else {
                    Toast("获取图片分类失败...");
                }
            });
        },
        getPhotoListByCateId(cateid){
            // 根据分类id,获取图片列表
            mobileApi.getimages(cateid).then(result => {
                if (result.data.status === 0) {
                    this.list = result.data.message ;
                } else {
                    Toast('获取图片列表失败');
                }
            });
        }
    }    
};
</script>

<style lang="scss" scoped>
* {
  touch-action: pan-y;
}

.photo-list {
  list-style: none;
  margin: 0;
  padding: 10px;
  padding-bottom: 0;
  li {
    background-color: #ccc;
    text-align: center;
    margin-bottom: 10px;
    box-shadow: 0 0 9px #999;
    position: relative;
    img {
      width: 100%;
      vertical-align: middle;
    }
    img[lazy="loading"] {
      width: 40px;
      height: 300px;
      margin: auto;
    }

    .info {
      color: white;
      text-align: left;
      position: absolute;
      bottom: 0;
      background-color: rgba(0, 0, 0, 0.4);
      max-height: 84px;
      min-width: 100%;
      .info-title {
        font-size: 14px;
      }
      .info-body {
        font-size: 13px;
      }
    }
  }
}


</style>    
