<template>
    <div>
        <div class="mui-content">
			<div class="mui-content-padded" style="margin: 5px;" >
				<br>
				<h5 style="margin: 2px 5px;">分类为：{{retit}}</h5>
				<br>
				发表时间:  {{1578496693497 | dateFormat }}
				<br>
				<div class="mui-input-row" style="margin: 1px 5px;">
					<textarea v-model="pojo.content" id="textarea" rows="20" placeholder="多行文本框"></textarea>
				</div>
			</div>
		</div>
		<div style="text-align:center;">
			<button class="button01" @click="clearInput" >清除文本</button>
			<button class="button00"  @click="handleClick" >发送</button>
			
        </div>
    </div>
</template>
<script>
import {Message} from '@/api/article'
export default {
    data() {
        return {
			pojo: {content:""},
			retit: '',
        }
    },
    created() {
		this.pojo.content = ''
    },
    methods: {
		clearInput(){
			this.pojo.content = ''
		},
        handleClick(){
            Message(this.pojo).then(res => {
				if(res.status === 200){
				switch(res.data)
					{
						case 1:
							this.retit = '推荐';
							break;
						case 2:
							this.retit = 'web';
							break;
						case 3:
							this.retit = '数据库';
							break;
						case 4:
							this.retit = '架构';
							break;
						case 5:
							this.retit = 'python';
							break;
						case 6:
							this.retit = 'java';
							break;
						case 7:
							this.retit = '程序人生';
							break;
						case 8:
							this.retit = '游戏';
							break;
						case 9:
							this.retit = '研发管理';
							break;
						default:
							//与 case 1 和 case 2 不同时执行的代码
							this.retit = '其他';
					}
				this.pojo.content = ''
				}
			});
        }
    },
}
</script>
<style lang="scss" scoped>
.button00 {
    background-color: #555555;
    border: none;
    color: white;
    padding: 10px 24px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 18px;
}
.button01{
	font-size: 18px;
	margin : 1px 10px;
	float:left;
	background-color: #f44336;
	color: white;

}
</style>
