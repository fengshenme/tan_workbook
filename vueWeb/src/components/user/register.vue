<template>
    <div>
       <div class="mui-content">
			<form class="mui-input-group" :model="pojo">
				<div class="mui-input-row">
					<label>账号</label>
					<input id='account' type="text" v-model="pojo.mobile" class="mui-input-clear mui-input" placeholder="请输入手机号">
				</div>
				<div class="mui-input-row">
					<label>密码</label>
					<input id='password' type="password" v-model="pojo.password" class="mui-input-clear mui-input" placeholder="请输入密码">
				</div>
				<div class="mui-input-row">
					<label>确认</label>
					<input id='password_confirm' v-model="password2" type="password" class="mui-input-clear mui-input" placeholder="请确认密码">
				</div>
				<div class="mui-input-row">
					<label>验证码</label>
					<input id='email' v-model="code" style="width:100px ;float: left;" type="email" class="mui-input-clear mui-input" placeholder="请输入验证码">
          <mt-button type="primary" style="width:120px ;float:right;height:36px;font-size: 14px; " @click="sendsms" :disabled="sendMsgDisabled" size="normal">
            <span v-show="sendMsgDisabled" >{{count}}秒后获取</span>
            <span v-show="!sendMsgDisabled" style="font-size: 14px;">获取验证码</span>
          </mt-button>
        </div>
			</form>
			<div class="mui-content-padded">
				<button id='reg' @click="register" v-bind:disabled='!checkto' class="mui-btn mui-btn-block mui-btn-primary">注册</button>
			</div>
			<div class="mui-content-padded">
				<p>注册真实可用，注册成功后的用户可用于登录，但是示例程序并未和服务端交互，用户相关数据仅存储于本地。</p>
			</div>
		</div> 
    </div>
</template>
<script>
import {Toast,Button} from 'mint-ui'
import {Register,Sendsms} from '@/api/user'
export default {
  data () {
    return {
      pojo: {password: '', nickname: '',mobile:'',},
      code: '',
      password2: '',
      checkto: true,
      timeer: null, // 发送验证码倒计时
      sendMsgDisabled: false,
      count: ''
    }
  },
  components:{
        // 用来注册子组件
        "mt-button": Button
    },
  created () {
  },
  methods: {
    register () {
      if(this.code == null && this.code.trim() == ''){
        Toast('请输入验证码')
      }else if(this.inputCheck(this.pojo.password,this.pojo.mobile,this.password2)){
        Register(this.pojo,this.code).then(res => {
          if (res.data.code===0) {
            Toast('注册成功')
            this.pojo = {}
            location.href='/#/user/longin'
          }
        })
      }
    },
    sendsms () {
      if(this.inputCheck(this.pojo.password,this.pojo.mobile,this.password2)){
            // 验证码倒计时
            const TIME_COUNT = 60;
            if (!this.timer) {
            this.count = TIME_COUNT;
            this.sendMsgDisabled = true;
            this.timer = setInterval(() => {
            if (this.count > 0 && this.count <= TIME_COUNT) {
                this.count--;
            } else {
                this.sendMsgDisabled = false
                clearInterval(this.timer);
                this.timer = null;
                    }
            }, 1000) 
        }
        Sendsms(this.pojo.mobile).then(res => {
            if(res.data.code === 0){
                Toast(res.data.message)
            }
        })
      }
    },
    inputCheck (password,mobile,password2) {
      const mobilere = /^[1][3,4,5,7,8][0-9]{9}$/
      const passre = /([^A-Za-z0-9\x21-\x7e])/
      if (passre.test(password)) {
        Toast( '密码需要由字母和数字组成')
      } else if (password.trim() === '' || password.length > 16 || password.length < 6) {
        Toast('密码长度不能少于6位或多于16位')
      } else if(password !== password2){
        Toast('两次输入密码不正确'+password2 + password)
      } else if (mobile == null || mobile.trim() == '') {
        Toast('请输入手机号')
      } else if (!mobilere.test(mobile)) {
        Toast('手机格式不对')
      } else{
        return true;
      }
    }
  }
}
</script>
<style lang="scss" scoped>

</style>
