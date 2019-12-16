<template>
    <div>
        <mt-swipe  :auto="4000" :stopPropagation=true>
            <!-- lunbotuList由父组件向子组件传值设定 -->
            <mt-swipe-item v-for="item in lunbotuList" :key="item.id">
                <img :src="item" alt="" :class="{'full':isfull}">
            </mt-swipe-item>
        </mt-swipe>
    </div>
</template>

<script>
export default {
    props:["lunbotuList","isfull"]
};
</script>

<style lang="scss" scoped>
.mint-swipe{
    height: 200px;
    .mint-swipe-item{
        text-align: center;
        img{
            height: 100%;
        }
    }
}
.full{
    width: 100%;
}
</style>