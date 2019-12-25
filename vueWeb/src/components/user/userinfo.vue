<template>
    <div >
        <div class="mui-page-content">
				<div class="mui-scroll-wrapper">
					<div class="mui-scroll">
						<ul  class="mui-table-view mui-table-view-chevron">
							<li class="mui-table-view-cell mui-media">
								<a v-if="$store.getters.ismobile" class="mui-navigate-right" >
									<div class="mui-media-body">
										<span class="mui-icon mui-icon-contact" id="head-img" src=""></span> 
                                        <router-link to="/user/login">未登录</router-link>
									</div>
								</a>
                                <a v-else class="mui-navigate-right" >
									<img class="mui-media-object mui-pull-left head-img" id="head-img" src="">
									<div class="mui-media-body">
										{{user.nickname==null ? "未设置昵称":user.nickname }}
										<p class='mui-ellipsis'>账号:{{user.mobile}}</p>
									</div>
								</a>
							</li>
						</ul>
						<ul class="mui-table-view mui-table-view-chevron">
							<li class="mui-table-view-cell">
								<a href="#account" class="mui-navigate-right">账号与安全</a>
							</li>
						</ul>
						<ul class="mui-table-view mui-table-view-chevron">
							<li class="mui-table-view-cell">
								<a href="#notifications" class="mui-navigate-right">新消息通知</a>
							</li>
							<li class="mui-table-view-cell">
								<a href="#general" class="mui-navigate-right">通用</a>
							</li>
							<li class="mui-table-view-cell">
								<router-link to="/user/message" class="mui-navigate-right">消息分类</router-link>
							</li>
						</ul>
						<ul class="mui-table-view mui-table-view-chevron">
							<li class="mui-table-view-cell">
								<router-link to="/user/file" class="mui-navigate-right">文件上传<i class="mui-pull-right update">1.0.0</i></router-link>
							</li>
							<li class="mui-table-view-cell">
								<router-link to="/user/fileadmin" class="mui-navigate-right">文件管理</router-link>
							</li>
						</ul>
						<ul  class="mui-table-view">
                            <li v-if ="$store.getters.ismobile" class="mui-table-view-cell" style="text-align: center;">
								<router-link to="/user/login"> 请登录</router-link>
							</li>
							<li v-else class="mui-table-view-cell" style="text-align: center;">
								<button style=" width:100%;height: 100%;" class="mui-btn-danger mui-btn-outlined" @click="logout()">退出登录</button>
							</li>
						</ul>
					</div>
				</div>
			</div>
			
    </div>
</template>

<script>
import { getUser,removeUser } from '@/utils/common'
import {Toast} from 'mint-ui'
import {Logout} from '@/api/user'
import {LoginStatus} from '@/api/user'
export default {
    data() {
        return {
            user:{}
        };
    },
    created() {
		this.user= getUser();
		this.loginStatus(this.user.mobile==undefined ? '1':this.user.mobile);
	},
   methods: {
	loginStatus(mobile){
		LoginStatus(mobile).then(res => {
			if (res.status===205) {
				this.$store.commit('ismobile',undefined)
				removeUser();
				this.user = getUser();
			}
		});
    },
    logout(){ 
		this.$store.commit('ismobile',undefined)
		removeUser()//清除登陆用户信息
      Logout().then(res => {
		if(res.status===205){
			Toast('退出成功') 
			// location.reload()
		}
      })
    }	
  }
}
</script>

<style lang="scss" scoped>
// div.mui-scroll-wrapper{
//     padding-top: 41px;
// }

</style>
