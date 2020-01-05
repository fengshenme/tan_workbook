<template>
    <div class="login-container">
        <div class="mui-content">
			<form id='login-form' class="mui-input-group" :model="pojo">
				<div class="mui-input-row">
					<label>账号</label>
					<input id='account' type="text" v-model="pojo.mobile" class="mui-input-clear mui-input" placeholder="请输入手机号">
				</div>
				<div class="mui-input-row">
					<label>密码</label>
					<input id='password' type="password" v-model="pojo.password" class="mui-input-clear mui-input" placeholder="请输入密码">
				</div>
			</form>
			<div class="mui-content-padded">
				<button id='login' type="button" @click="login" class="mui-btn mui-btn-block mui-btn-primary">登录</button>
				<div class="link-area">
					<router-link id='reg' to='/user/register' >注册账号</router-link> <span class="spliter">|</span> <a id='forgetPassword'>忘记密码</a>
				</div>
			</div>
			<div class="mui-content-padded oauth-area">

			</div>
		</div>
    </div>
</template>

<script>
import {Login} from '@/api/user'
import {Toast} from 'mint-ui'
import { setUser } from '@/utils/common'
export default {
    data(){
        return {
            pojo: {mobile: '',password: ''},
            checkto : true
        }
	},
	created() {
	},
    methods: {
        login () {    
            Login(this.pojo).then( res =>{
                if(res.status === 200){
					//保存用户信息
					setUser(res.data.name,res.data.token,this.pojo.mobile)
					//存入vuex,公共data
					this.$store.commit('increment',res.data.token)
					this.$store.commit('ismobile',this.pojo.mobile)
					this.pojo = {}
					location.href='/#/user/userinfo' //主页
                }else{
                    Toast(res.data.message)
                }
            })
        },
    }
}
</script>
<style lang="scss" scoped>

</style>
