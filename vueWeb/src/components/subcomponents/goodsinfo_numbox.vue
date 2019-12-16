<template>
        <div class="mui-numbox" data-numbox-min='1' :data-numbex-max='max'>
            <button class="mui-btn mui-numbox-btn-minus" type="button" >-</button>
                <input id="test" class="mui-numbox-input"  type="number" value="1"  @change="countChanged" ref="numbox"/>
            <button class="mui-btn mui-numbox-btn-plus" type="button"  >+</button>
        </div>
</template>

<script>
import mui from "../../assets/js/mui.min.js"
export default {
    mounted(){
        // 初始化数字选择框组件
        mui(".mui-numbox").numbox();
    },
    methods: {
        countChanged() {
            //console.log(this.$refs.numbox.value);
            this.$emit("getcount",parseInt(this.$refs.numbox.value))
        }
    },
    props: ['max'],
    watch: {
        
        // 属性监听
        // max:function(newVal,oldVal){
        max:function(newVal){
            mui(".mui-numbox").numbox().setOption("max",newVal);
        },
        
    }
}
</script>

<style lang="scss" scoped>

// 去除用chome时出现的上下箭头

// input::-webkit-outer-spin-button,
// input::-webkit-inner-spin-button {
//     -webkit-appearance: none;
// }
// 去除用火狐时出现的上下箭头
input[type="number"] {
    -moz-appearance: textfield;
}
</style>
